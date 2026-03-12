#pragma once

#include <optional>
#include <string>
#include <string_view>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Equity And Index End Of Day Summary Message Type
struct EquityAndIndexEndOfDaySummaryMessageType {

    static constexpr auto name = "equity_and_index_end_of_day_summary_message_type";
    static constexpr auto nullable = true;

    EquityAndIndexEndOfDaySummaryMessageType() = default;

    // set equity_and_index_end_of_day_summary_message_type
    void set(const char* value) {
        data = value;
    }

    // set equity_and_index_end_of_day_summary_message_type
    void set(const std::string& value) {
        data = value;
    }

    // set equity_and_index_end_of_day_summary_message_type
    void set(std::string_view value) {
        data = std::string{value};
    }

    // set equity_and_index_end_of_day_summary_message_type
    void set(const char value) {
        data = {value};
    }

    // reset equity_and_index_end_of_day_summary_message_type field
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
        // trim trailing spaces
        while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }
        return result;
    }

    // append equity_and_index_end_of_day_summary_message_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(sanitize(*data));
        }

        return builder.AppendNull();
    }

    // equity_and_index_end_of_day_summary_message_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}