#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Short Sale Threshold Indicator
struct ShortSaleThresholdIndicator {

    static constexpr auto name = "short_sale_threshold_indicator";
    static constexpr auto nullable = true;

    ShortSaleThresholdIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Y") { return "Restricted"; }
        if (value == "N") { return "Not Restricted"; }
        if (value == " ") { return "Not Available"; }
        return sanitize(value);
    }

    // set short_sale_threshold_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set short_sale_threshold_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set short_sale_threshold_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset short_sale_threshold_indicator field
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

    // append short_sale_threshold_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // short_sale_threshold_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}