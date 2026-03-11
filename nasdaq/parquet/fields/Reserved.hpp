#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Reserved
struct Reserved {

    static constexpr auto name = "reserved";
    static constexpr auto nullable = true;

    Reserved() = default;

    // set reserved
    void set(const char* value) {
        data = value;
    }

    // set reserved
    void set(const std::string& value) {
        data = value;
    }

    // set reserved
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set reserved
    void set(const char value) {
        data = {value};
    }

    // reset reserved field
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

    // append reserved
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // reserved schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}