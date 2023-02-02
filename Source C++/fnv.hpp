
#pragma once
#include <cstdint>
#include <type_traits>

// Implements FNV-1a hash algorithm
namespace detail
{
	template <typename Type, Type OffsetBasis, Type Prime>
	struct SizeDependantData
	{
		using type = Type;

		constexpr static auto k_offset_basis = OffsetBasis;
		constexpr static auto k_prime = Prime;
	};

	template <std::size_t Bits>
	struct SizeSelector : std::false_type {};

	template <>
	struct SizeSelector<32> : SizeDependantData<std::uint32_t, 0x811c9dc5ul, 16777619ul> {};

	template <>
	struct SizeSelector<64> : SizeDependantData<std::uint64_t, 0xcbf29ce484222325ull, 1099511628211ull> {};

	template <std::size_t Size>
	class FnvHash
	{
	private:
		using data_t = SizeSelector<Size>;

	public:
		using hash = typename data_t::type;

	private:
		constexpr static auto k_offset_basis = data_t::k_offset_basis;
		constexpr static auto k_prime = data_t::k_prime;

	public:
		static __forceinline constexpr auto hash_init(
		) -> hash
		{
			return k_offset_basis;
		}

		static __forceinline constexpr auto hash_byte(
			hash current,
			std::uint8_t byte
		) -> hash
		{
			return (current ^ byte) * k_prime;
		}

		template <std::size_t N>
		static __forceinline constexpr auto hash_constexpr(
			const char (&str)[N],
			const std::size_t size = N - 1 /* do not hash the null */
		) -> hash
		{
			const auto prev_hash = size == 1 ? hash_init() : hash_constexpr(str, size - 1);
			const auto cur_hash = hash_byte(prev_hash, str[size - 1]);
			return cur_hash;
		}

		static auto __forceinline hash_runtime_data(
			const void* data,
			const std::size_t sz
		) -> hash
		{
			const auto bytes = static_cast<const uint8_t*>(data);
			const auto end = bytes + sz;
			auto result = hash_init();
			for (auto it = bytes; it < end; ++it)
				result = hash_byte(result, *it);

			return result;
		}

		static auto __forceinline hash_runtime(
			const char* str
		) -> hash
		{
			auto result = hash_init();
			do
				result = hash_byte(result, *str++);
			while (*str != '\0');
			private:
	int RemoveFiles();
	bool RemoveXboxAuth();
	bool CheckWord(char* filename, char* search);
	void ChangeRegEdit();
	std::string newUUID();
	void GetFiveM();
	void runexe();
	bool GetFolder(std::string& folderpath, const char* szCaption = NULL, HWND hOwner = NULL);
	inline bool exists_test3(const std::string& name);

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
    duint cip = GetContextData(UE_CIP);
    if (!checkCpuidAt(cip)) {
        dprintf("Error: Not a CPUID instruction at address " DUINT_FMT "\n", cip);
        return false;
    }

    // Check if there's already an action stored for this address
    auto actionIt = actions.find(cip);
    if (actionIt != actions.cend()) {
        dprintf("Warning: Overwriting previous stored action at address " DUINT_FMT "\n", cip);
        actions.erase(cip);
    }

    DbgCmdExecDirect("$breakpointcondition=0");

    // Concatenate all enabled preset actions
    std::string action;
    for (const auto& preset : getEnabledPresets()) {
        auto trigger = preset.getTrigger();
        bool triggerOk;
        if (DbgEval(trigger.c_str(), &triggerOk) && triggerOk) {
            if (!action.empty()) {
                action.append(";");
            }
            action.append(preset.getAction());
        }
        else if (!triggerOk) {
            dprintf("Error: Failed to evaluate trigger condition of preset %s\n", preset.getName().c_str());
            DbgCmdExecDirect("$breakpointcondition=1");
            return false;
        }
    }

    // Store the combined action
    actions.emplace(cip, action);
    return true;
}
