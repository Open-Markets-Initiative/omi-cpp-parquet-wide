#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Security Condition
struct SecurityCondition {

    static constexpr auto name = "security_condition";
    static constexpr auto nullable = true;

    SecurityCondition() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "O") { return "Normal"; }
        if (value == "D") { return "Ex Dividend"; }
        if (value == "C") { return "Ex Cap"; }
        if (value == "R") { return "Ex Rights"; }
        if (value == "E") { return "Ex Entitlement"; }
        if (value == "S") { return "Dealingstemporarilysuspended"; }
        if (value == "N") { return "Not Listed"; }
        return sanitize(value);
    }

    // set security_condition
    void set(const char* value) {
        data = translate(value);
    }

    // set security_condition
    void set(const std::string& value) {
        data = translate(value);
    }

    // set security_condition
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset security_condition field
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

    // append security_condition
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // security_condition schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}