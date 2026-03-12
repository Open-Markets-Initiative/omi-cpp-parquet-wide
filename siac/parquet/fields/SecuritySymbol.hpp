#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Security Symbol
struct SecuritySymbol {

    static constexpr auto name = "security_symbol";
    static constexpr auto nullable = true;

    SecuritySymbol() = default;

    // set security_symbol
    void set(const char* value) {
        data = value;
    }

    // set security_symbol
    void set(const std::string& value) {
        data = value;
    }

    // set security_symbol
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set security_symbol
    void set(const char value) {
        data = {value};
    }

    // reset security_symbol field
    void reset() {
        data.reset();
    }

    // sanitize to valid utf-8 ascii
    static std::string sanitize(const std::string& value) {
        std::string result;
        result.reserve(value.size());
        for (unsigned char c : value) {
            if (c >= 0x20 && c < 0x7F) {
                result.push_back(static_cast<char>(c));
            }
        }
        // trim trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

    // append security_symbol
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // security_symbol schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}