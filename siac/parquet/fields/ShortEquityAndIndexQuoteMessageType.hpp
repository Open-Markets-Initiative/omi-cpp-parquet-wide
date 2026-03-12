#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Short Equity And Index Quote Message Type
struct ShortEquityAndIndexQuoteMessageType {

    static constexpr auto name = "short_equity_and_index_quote_message_type";
    static constexpr auto nullable = true;

    ShortEquityAndIndexQuoteMessageType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == " ") { return "Regular Trading"; }
        if (value == "F") { return "Non Firm Quote"; }
        if (value == "I") { return "Indicative Value"; }
        if (value == "R") { return "Rotation"; }
        if (value == "T") { return "Trading Halted"; }
        if (value == "A") { return "Eligible For Automatic Execution"; }
        if (value == "B") { return "Bid Contains Customer Trading Interest"; }
        if (value == "O") { return "Offer Contains Customer Trading Interest"; }
        if (value == "C") { return "Both Bid And Offer Contain Customer Trading Interest"; }
        if (value == "X") { return "Offer Side Of Quote Not Firm Bid Side Firm"; }
        if (value == "Y") { return "Bid Side Of Quote Not Firm Offer Side Firm"; }
        return sanitize(value);
    }

    // set short_equity_and_index_quote_message_type
    void set(const char* value) {
        data = translate(value);
    }

    // set short_equity_and_index_quote_message_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set short_equity_and_index_quote_message_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset short_equity_and_index_quote_message_type field
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

    // append short_equity_and_index_quote_message_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // short_equity_and_index_quote_message_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}