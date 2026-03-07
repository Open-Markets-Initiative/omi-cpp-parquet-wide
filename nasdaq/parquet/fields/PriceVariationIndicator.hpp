#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Price Variation Indicator
struct PriceVariationIndicator {

    static constexpr auto name = "price_variation_indicator";
    static constexpr auto nullable = true;

    PriceVariationIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "L") { return "Less Than 1 Percent"; }
        if (value == "1") { return "Less Than 2 Percent"; }
        if (value == "2") { return "Less Than 3 Percent"; }
        if (value == "3") { return "Less Than 4 Percent"; }
        if (value == "4") { return "Less Than 5 Percent"; }
        if (value == "5") { return "Less Than 6 Percent"; }
        if (value == "6") { return "Less Than 7 Percent"; }
        if (value == "7") { return "Less Than 8 Percent"; }
        if (value == "8") { return "Less Than 9 Percent"; }
        if (value == "9") { return "Less Than 10 Percent"; }
        if (value == "A") { return "Less Than 20 Percent"; }
        if (value == "B") { return "Less Than 30 Percent"; }
        if (value == "C") { return "More Than 30 Percent"; }
        if (value == " ") { return "Not Available"; }
        return sanitize(value);
    }

    // set price_variation_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set price_variation_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set price_variation_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset price_variation_indicator field
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

    // append price_variation_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // price_variation_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}