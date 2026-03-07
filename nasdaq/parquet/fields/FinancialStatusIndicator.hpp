#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Financial Status Indicator
struct FinancialStatusIndicator {

    static constexpr auto name = "financial_status_indicator";
    static constexpr auto nullable = true;

    FinancialStatusIndicator() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "D") { return "Deficient"; }
        if (value == "E") { return "Delinquent"; }
        if (value == "Q") { return "Bankrupt"; }
        if (value == "S") { return "Suspended"; }
        if (value == "G") { return "Deficient And Bankrupt"; }
        if (value == "H") { return "Deficient And Delinquent"; }
        if (value == "J") { return "Delinquent And Bankrupt"; }
        if (value == "K") { return "Deficient Delinquent And Bankrupt"; }
        if (value == "C") { return "Creations And Redemptions Suspended"; }
        if (value == "N") { return "Normal"; }
        if (value == " ") { return "Not Available"; }
        return sanitize(value);
    }

    // set financial_status_indicator
    void set(const char* value) {
        data = translate(value);
    }

    // set financial_status_indicator
    void set(const std::string& value) {
        data = translate(value);
    }

    // set financial_status_indicator
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset financial_status_indicator field
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

    // append financial_status_indicator
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // financial_status_indicator schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}