#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Luld Reference Price Tier
struct LuldReferencePriceTier {

    static constexpr auto name = "luld_reference_price_tier";
    static constexpr auto nullable = true;

    LuldReferencePriceTier() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "1") { return "Tier 1"; }
        if (value == "2") { return "Tier 2"; }
        if (value == " ") { return "Not Available"; }
        return sanitize(value);
    }

    // set luld_reference_price_tier
    void set(const char* value) {
        data = translate(value);
    }

    // set luld_reference_price_tier
    void set(const std::string& value) {
        data = translate(value);
    }

    // set luld_reference_price_tier
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset luld_reference_price_tier field
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

    // append luld_reference_price_tier
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // luld_reference_price_tier schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}