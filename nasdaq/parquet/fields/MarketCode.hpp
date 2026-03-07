#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Market Code
struct MarketCode {

    static constexpr auto name = "market_code";
    static constexpr auto nullable = true;

    MarketCode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Q") { return "Nasdaq"; }
        if (value == "B") { return "Nasdaq Texas"; }
        if (value == "X") { return "Psx"; }
        return sanitize(value);
    }

    // set market_code
    void set(const char* value) {
        data = translate(value);
    }

    // set market_code
    void set(const std::string& value) {
        data = translate(value);
    }

    // set market_code
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset market_code field
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

    // append market_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // market_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}