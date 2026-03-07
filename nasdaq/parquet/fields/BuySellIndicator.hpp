#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Buy Sell Indicator
struct BuySellIndicator {

    static constexpr auto name = "buy_sell_indicator";
    static constexpr auto nullable = true;

    BuySellIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "B") { return "Buy"; }
        if (value == "S") { return "Sell"; }
        return sanitize(value);
    }

    // set buy_sell_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set buy_sell_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set buy_sell_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset buy_sell_indicator field
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

    // append buy_sell_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // buy_sell_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}