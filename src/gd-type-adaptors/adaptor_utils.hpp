#ifndef GDMSGPK_ADAPTOR_UTILS_HPP
#define GDMSGPK_ADAPTOR_UTILS_HPP

#include <vector>
#include <cstring>
#include <type_traits>

namespace adaptor_utils {

    std::vector<unsigned char> char32ToByteArray(const char32_t *str, size_t size) {
        std::vector<unsigned char> bytes(size * sizeof(char32_t));
        std::memcpy(bytes.data(), str, size * sizeof(char32_t));
        return bytes;
    }

    std::vector<char32_t> byteArrayToChar32(const unsigned char *bytes, size_t size) {
        std::vector<char32_t> str(size / sizeof(char32_t));
        std::memcpy(str.data(), bytes, size);
        return str;
    }

}

#endif