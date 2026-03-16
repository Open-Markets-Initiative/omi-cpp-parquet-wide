#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Quantity Notation
struct QuantityNotation {

    static constexpr auto name = "quantity_notation";
    static constexpr auto nullable = true;

    QuantityNotation() = default;

    // set quantity_notation
    void set(const char* value) {
        data = value;
    }

    // set quantity_notation
    void set(const std::string& value) {
        data = value;
    }

    // set quantity_notation
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set quantity_notation
    void set(const char value) {
        data = {value};
    }

    // reset quantity_notation field
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

    // append quantity_notation
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // quantity_notation schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}