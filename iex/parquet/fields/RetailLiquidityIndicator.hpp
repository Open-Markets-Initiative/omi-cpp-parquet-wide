#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace iex {

// field: Retail Liquidity Indicator
struct RetailLiquidityIndicator {

    static constexpr auto name = "retail_liquidity_indicator";
    static constexpr auto nullable = true;

    RetailLiquidityIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == " ") { return "Not Applicable"; }
        if (value == "A") { return "Buy Interest"; }
        if (value == "B") { return "Sell Interest"; }
        if (value == "C") { return "Buy And Sell Interest"; }
        return sanitize(value);
    }

    // set retail_liquidity_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set retail_liquidity_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set retail_liquidity_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset retail_liquidity_indicator field
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

    // append retail_liquidity_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // retail_liquidity_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}