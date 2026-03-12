#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Bbo Indicator
struct BboIndicator {

    static constexpr auto name = "bbo_indicator";
    static constexpr auto nullable = true;

    BboIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "No Best Bid Change Or Best Offer Change"; }
        if (value == "B") { return "No Best Bid Change Quote Contains Best Offer"; }
        if (value == "C") { return "No Best Bid Change Best Offer Appendage"; }
        if (value == "D") { return "No Best Bid Change No Best Offer"; }
        if (value == "E") { return "Quote Contains Best Bid No Best Offer Change"; }
        if (value == "F") { return "Quote Contains Best Bid Quote Contains Best Offer"; }
        if (value == "G") { return "Quote Contains Best Bid Best Offer Appendage"; }
        if (value == "H") { return "Quote Contains Best Bid No Best Offer"; }
        if (value == "I") { return "No Best Bid No Best Offer Change"; }
        if (value == "J") { return "No Best Bid Quote Contains Best Offer"; }
        if (value == "K") { return "No Best Bid Best Offer Appendage"; }
        if (value == "L") { return "No Best Bid No Best Offer"; }
        if (value == "M") { return "Best Bid Appendage No Best Offer Change"; }
        if (value == "N") { return "Best Bid Appendage Quote Contains Best Offer"; }
        if (value == "O") { return "Best Bid Appendage Best Offer Appendage"; }
        if (value == "P") { return "Best Bid Appendage No Best Offer"; }
        if (value == " ") { return "Not Included In The Bbo"; }
        return sanitize(value);
    }

    // set bbo_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set bbo_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set bbo_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset bbo_indicator field
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

    // append bbo_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bbo_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}