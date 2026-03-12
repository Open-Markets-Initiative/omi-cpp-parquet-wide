#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Equity And Index Last Sale Message Type
struct EquityAndIndexLastSaleMessageType {

    static constexpr auto name = "equity_and_index_last_sale_message_type";
    static constexpr auto nullable = true;

    EquityAndIndexLastSaleMessageType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Canc"; }
        if (value == "B") { return "Oseq"; }
        if (value == "C") { return "Cncl"; }
        if (value == "D") { return "Late"; }
        if (value == "E") { return "Cnco"; }
        if (value == "F") { return "Open"; }
        if (value == "G") { return "Cnol"; }
        if (value == "H") { return "Opnl"; }
        if (value == "I") { return "Auto"; }
        if (value == "J") { return "Reop"; }
        if (value == "K") { return "Ajst"; }
        if (value == "L") { return "Sprd"; }
        if (value == "M") { return "Stdl"; }
        if (value == "N") { return "Stpd"; }
        if (value == "O") { return "Cstp"; }
        if (value == "P") { return "Bwrt"; }
        if (value == "Q") { return "Cmbo"; }
        if (value == "R") { return "Spim"; }
        if (value == "S") { return "Isoi"; }
        if (value == "T") { return "Bnmt"; }
        if (value == "X") { return "Xmpt"; }
        return sanitize(value);
    }

    // set equity_and_index_last_sale_message_type
    void set(const char* value) {
        data = translate(value);
    }

    // set equity_and_index_last_sale_message_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set equity_and_index_last_sale_message_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset equity_and_index_last_sale_message_type field
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

    // append equity_and_index_last_sale_message_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // equity_and_index_last_sale_message_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}