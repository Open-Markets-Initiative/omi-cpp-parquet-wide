#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace iex {

// field: Reason
struct Reason {

    static constexpr auto name = "reason";
    static constexpr auto nullable = true;

    Reason() = default;

    // set reason
    void set(const char* value) {
        data = value;
    }

    // set reason
    void set(const std::string& value) {
        data = value;
    }

    // set reason
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set reason
    void set(const char value) {
        data = {value};
    }

    // reset reason field
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

    // append reason
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // reason schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}