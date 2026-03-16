#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Sedol Code
struct SedolCode {

    static constexpr auto name = "sedol_code";
    static constexpr auto nullable = true;

    SedolCode() = default;

    // set sedol_code
    void set(const char* value) {
        data = value;
    }

    // set sedol_code
    void set(const std::string& value) {
        data = value;
    }

    // set sedol_code
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set sedol_code
    void set(const char value) {
        data = {value};
    }

    // reset sedol_code field
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

    // append sedol_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // sedol_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}