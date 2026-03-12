#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Expiration Month
struct ExpirationMonth {

    static constexpr auto name = "expiration_month";
    static constexpr auto nullable = true;

    ExpirationMonth() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "January"; }
        if (value == "M") { return "January"; }
        if (value == "B") { return "February"; }
        if (value == "N") { return "February"; }
        if (value == "C") { return "March"; }
        if (value == "O") { return "March"; }
        if (value == "D") { return "April"; }
        if (value == "P") { return "April"; }
        if (value == "E") { return "May"; }
        if (value == "Q") { return "May"; }
        if (value == "F") { return "June"; }
        if (value == "R") { return "June"; }
        if (value == "G") { return "July"; }
        if (value == "S") { return "July"; }
        if (value == "H") { return "August"; }
        if (value == "T") { return "August"; }
        if (value == "I") { return "September"; }
        if (value == "U") { return "September"; }
        if (value == "J") { return "October"; }
        if (value == "V") { return "October"; }
        if (value == "K") { return "November"; }
        if (value == "W") { return "November"; }
        if (value == "L") { return "December"; }
        if (value == "X") { return "December"; }
        return sanitize(value);
    }

    // set expiration_month
    void set(const char* value) {
        data = translate(value);
    }

    // set expiration_month
    void set(const std::string& value) {
        data = translate(value);
    }

    // set expiration_month
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset expiration_month field
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

    // append expiration_month
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // expiration_month schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}