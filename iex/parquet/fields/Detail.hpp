#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace iex {

// field: Detail
struct Detail {

    static constexpr auto name = "detail";
    static constexpr auto nullable = true;

    Detail() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == " ") { return "No Price Test In Place"; }
        if (value == "A") { return "Activated"; }
        if (value == "C") { return "Continued"; }
        if (value == "D") { return "Deactivated"; }
        if (value == "N") { return "Not Available"; }
        return sanitize(value);
    }

    // set detail
    void set(const char* value) {
        data = translate(value);
    }

    // set detail
    void set(const std::string& value) {
        data = translate(value);
    }

    // set detail
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset detail field
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
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

    // append detail
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // detail schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}