#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Exchange Code
struct ExchangeCode {

    static constexpr auto name = "exchange_code";
    static constexpr auto nullable = true;

    ExchangeCode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Amsterdam Equity Derivatives"; }
        if (value == "B") { return "Brussels Equity Derivatives"; }
        if (value == "C") { return "Paris Equity Underlyings"; }
        if (value == "D") { return "Brussels Cash Underlyings"; }
        if (value == "F") { return "Brussels Index Derivatives"; }
        if (value == "G") { return "Amsterdam Cash Underlyings"; }
        if (value == "H") { return "Lisbon Cash Underlyings"; }
        if (value == "J") { return "Paris Index Derivatives"; }
        if (value == "K") { return "Amsterdam Index Derivatives"; }
        if (value == "M") { return "Lisbon Index Derivatives"; }
        if (value == "P") { return "Paris Equity Derivatives"; }
        if (value == "R") { return "Amsterdam Commodities Derivatives"; }
        if (value == "S") { return "Lisbon Equity Derivatives"; }
        if (value == "Y") { return "Paris Commodities Derivatives"; }
        if (value == "Z") { return "Amsterdam Currency Derivatives"; }
        if (value == "N") { return "Oslo Index Derivatives"; }
        if (value == "O") { return "Oslo Equity Derivatives"; }
        if (value == "L") { return "Oslo Cash Underlying"; }
        return sanitize(value);
    }

    // set exchange_code
    void set(const char* value) {
        data = translate(value);
    }

    // set exchange_code
    void set(const std::string& value) {
        data = translate(value);
    }

    // set exchange_code
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset exchange_code field
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

    // append exchange_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // exchange_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}