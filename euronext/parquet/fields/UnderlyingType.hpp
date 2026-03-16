#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Underlying Type
struct UnderlyingType {

    static constexpr auto name = "underlying_type";
    static constexpr auto nullable = true;

    UnderlyingType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Basketwith Commodity"; }
        if (value == "B") { return "Basket"; }
        if (value == "C") { return "Commodity"; }
        if (value == "D") { return "Depositary Receipt"; }
        if (value == "F") { return "Future"; }
        if (value == "G") { return "Currency Leveraged Index"; }
        if (value == "H") { return "Other"; }
        if (value == "I") { return "Index"; }
        if (value == "J") { return "Bonds"; }
        if (value == "K") { return "Stock Dividend"; }
        if (value == "L") { return "Leveraged Index"; }
        if (value == "N") { return "Interest Rate"; }
        if (value == "O") { return "Other Derivative"; }
        if (value == "P") { return "Commodity Index"; }
        if (value == "Q") { return "Commodity Leveraged Index"; }
        if (value == "R") { return "Right"; }
        if (value == "S") { return "Stock"; }
        if (value == "T") { return "Credit"; }
        if (value == "U") { return "Fund"; }
        if (value == "V") { return "Currency"; }
        if (value == "W") { return "Stock Warrant"; }
        if (value == "X") { return "Exchange Rate"; }
        if (value == "Z") { return "Security Leveraged Index"; }
        return sanitize(value);
    }

    // set underlying_type
    void set(const char* value) {
        data = translate(value);
    }

    // set underlying_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set underlying_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset underlying_type field
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

    // append underlying_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}