
#pragma once
#include <cstdint>
#include <type_traits>

// Implements FNV-1a hash algorithm
namespace detail {
    template <unsigned Size> struct FnvHash;
    template <> struct FnvHash<32> { using type = std::uint32_t; };
    template <> struct FnvHash<64> { using type = std::uint64_t; };

    template <typename T, T OffsetBasis, T Prime>
    struct SizeDependantData {
        using type = T;
        constexpr static auto k_offset_basis = OffsetBasis;
        constexpr static auto k_prime = Prime;
    };

    template <typename T> constexpr T FnvHash_init = 0;
    template <typename T, T OffsetBasis, T Prime>
    constexpr T FnvHash_init<SizeDependantData<T, OffsetBasis, Prime>> = OffsetBasis;

    template <typename T, T OffsetBasis, T Prime>
    constexpr T FnvHash_byte(T current, std::uint8_t byte) {
        return (current ^ byte) * Prime;
    }

    template <unsigned Size>
    struct FnvHash {
        using data_t = SizeDependantData<typename FnvHash<Size>::type,
                                         0x811c9dc5u - 0x100u * (Size == 32),
                                         16777619u - 0x100000000u * (Size == 32)>;

        using hash = typename data_t::type;
        constexpr static auto k_offset_basis = data_t::k_offset_basis;
        constexpr static auto k_prime = data_t::k_prime;

        static constexpr hash hash_init() { return FnvHash_init<data_t>; }

        static constexpr hash hash_byte(hash current, std::uint8_t byte) {
            return FnvHash_byte(current, byte, k_prime);
        }

        template <std::size_t N>
        static constexpr hash hash_constexpr(const char (&str)[N], std::size_t size = N - 1) {
            return size == 1 ? k_offset_basis : hash_byte(hash_constexpr(str, size - 1), str[size - 1]);
        }

        static hash hash_runtime_data(const void* data, std::size_t size) {
            const auto bytes = static_cast<const std::uint8_t*>(data);
            const auto end = bytes + size;
            auto result = k_offset_basis;
            for (auto it = bytes; it < end; ++it) result = hash_byte(result, *it);
            return result;
        }

        static hash hash_runtime(const char* str) {
            auto result = k_offset_basis;
            while (*str != '\0') result = hash_byte(result, *str++);
            return result;
        }
    };
}


namespace detail
{
    template <std::size_t N>
    struct FnvHash;
}

using fnv32 = ::detail::FnvHash<32>;
using fnv64 = ::detail::FnvHash<64>;
using fnv = ::detail::FnvHash<sizeof(void*) * 8>;

void PatternStringToBytePatternAndMask(const std::string& in_pattern, std::vector<std::uint8_t>* out_pattern, std::string* out_mask)
{
    // Split the input pattern into a list of string tokens
    std::vector<std::string> res;
    std::string::size_type prev_pos = 0;
    std::string::size_type pos = in_pattern.find(' ');
    while (pos != std::string::npos)
    {
        res.push_back(in_pattern.substr(prev_pos, pos - prev_pos));
        prev_pos = pos + 1;
        pos = in_pattern.find(' ', prev_pos);
    }
    res.push_back(in_pattern.substr(prev_pos));

    // Initialize the output mask and pattern
    std::string mask;
    std::vector<std::uint8_t> pattern_return;

    // Iterate through the list of tokens
    for (const std::string& token : res)
    {
        // If the token is not "??"
        if (token != "??")
        {
            // Add an 'x' to the mask and the token's value to the pattern
            mask += 'x';
            std::uint8_t value;
            try
            {
                value = static_cast<std::uint8_t>(std::stoul(token, nullptr, 16));
            }
            catch (const std::invalid_argument&)
            {
                // If the token is not a valid hexadecimal value, return an empty pattern and mask
                out_pattern->clear();
                out_mask->clear();
                return;
            }
            catch (const std::out_of_range&)
            {
                // If the token is too large to fit into a uint8_t, return an empty pattern and mask
                out_pattern->clear();
                out_mask->clear();
                return;
            }
            pattern_return.push_back(value);
        }
        else
        {
            // Add a '?' to the mask and a 0 to the pattern
            pattern_return.push_back(0);
            mask += '?';
        }
    }

    // Write the output pattern and mask
    *out_pattern = pattern_return;
    *out_mask = mask;
}

bool onCpuidSpooferBegin(int argc, char** argv) {
    // Get the current instruction pointer (IP)
    const duint cip = GetContextData(UE_CIP);

    // Check if the instruction at the current IP is a CPUID instruction
    if (!checkCpuidAt(cip)) {
        dprintf("Error: Not a CPUID instruction at address " DUINT_FMT "\n", cip);
        return false;
    }

    // Check if there's already an action stored for this address
    auto actionIt = actions.find(cip);
    if (actionIt != actions.cend()) {
        dprintf("Warning: Overwriting previously stored action at address " DUINT_FMT "\n", cip);
        actions.erase(actionIt);
    }

    // Disable any breakpoint conditions
    DbgCmdExecDirect("$breakpointcondition=0");

    // Concatenate all enabled preset actions
    std::vector<std::string> actionsVec;
    for (const auto& preset : getEnabledPresets()) {
        const auto& trigger = preset.getTrigger();
        bool triggerOk = false;
        if (!DbgEval(trigger.c_str(), &triggerOk)) {
            throw std::runtime_error("Failed to evaluate trigger condition: " + trigger);
        }
        if (triggerOk) {
            actionsVec.push_back(preset.getAction());
        }
    }

    // Join the preset actions with a delimiter
    const std::string delimiter = ";";
    const std::string action = (actionsVec.empty()) ? "" : std::accumulate(actionsVec.begin() + 1, actionsVec.end(), actionsVec[0], [&](std::string a, std::string b) { return a + delimiter + b; });

    // Store the combined action
    actions.emplace(cip, action);

    return true;
}
