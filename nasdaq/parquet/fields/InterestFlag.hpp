#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Interest Flag
struct InterestFlag {

    static constexpr auto name = "interest_flag";
    static constexpr auto nullable = true;

    InterestFlag() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "B") { return "Buy Side"; }
        if (value == "S") { return "Sell Side"; }
        if (value == "A") { return "Both Sides"; }
        if (value == "N") { return "No Rpi Orders Available"; }
        return sanitize(value);
    }

    // set interest_flag
    void set(const char* value) {
        data = translate(value);
    }

    // set interest_flag
    void set(const std::string& value) {
        data = translate(value);
    }

    // set interest_flag
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset interest_flag field
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

    // append interest_flag
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // interest_flag schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}