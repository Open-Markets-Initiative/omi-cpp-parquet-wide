#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Underlying Price Denominator Code
struct UnderlyingPriceDenominatorCode {

    static constexpr auto name = "underlying_price_denominator_code";
    static constexpr auto nullable = true;

    UnderlyingPriceDenominatorCode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Ten"; }
        if (value == "B") { return "Hundred"; }
        if (value == "C") { return "Thousand"; }
        if (value == "D") { return "Ten Thousand"; }
        if (value == "E") { return "Hundred Thousand"; }
        if (value == "F") { return "Million"; }
        if (value == "G") { return "Ten Million"; }
        if (value == "H") { return "Hundred Million"; }
        if (value == "I") { return "No Fraction"; }
        return sanitize(value);
    }

    // set underlying_price_denominator_code
    void set(const char* value) {
        data = translate(value);
    }

    // set underlying_price_denominator_code
    void set(const std::string& value) {
        data = translate(value);
    }

    // set underlying_price_denominator_code
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset underlying_price_denominator_code field
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

    // append underlying_price_denominator_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_price_denominator_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}