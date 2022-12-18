
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

using fnv32 = ::detail::FnvHash<32>;
using fnv64 = ::detail::FnvHash<64>;
using fnv = ::detail::FnvHash<sizeof(void*) * 8>;

void PatternStringToBytePatternAndMask(const string& in_pattern, vector<byte>* out_pattern, string* out_mask) {
    // Split the input pattern into a list of string tokens
    vector<string> res = split(in_pattern, ' ');

    // Initialize the output mask and pattern
    string mask;
    vector<byte> pattern_return;

    // Iterate through the list of tokens
    for (const string& token : res) {
        // If the token is not "??"
        if (token != "??") {
            // Add an 'x' to the mask and the token's value to the pattern
            mask += "x";
            pattern_return.push_back((byte)StrHexToInt(token));
        }
        else {
            // Add a '?' to the mask and a 0 to the pattern
            pattern_return.push_back(0);
            mask += "?";
        }
    }

    // Write the output pattern and mask
    *out_pattern = pattern_return;
    *out_mask = mask;
}
