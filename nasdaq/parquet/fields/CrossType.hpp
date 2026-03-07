#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Cross Type
struct CrossType {

    static constexpr auto name = "cross_type";
    static constexpr auto nullable = true;

    CrossType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "O") { return "Opening"; }
        if (value == "C") { return "Closing"; }
        if (value == "H") { return "Halted Or Paused"; }
        if (value == "A") { return "Extended Close"; }
        return sanitize(value);
    }

    // set cross_type
    void set(const char* value) {
        data = translate(value);
    }

    // set cross_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set cross_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset cross_type field
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

    // append cross_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // cross_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}