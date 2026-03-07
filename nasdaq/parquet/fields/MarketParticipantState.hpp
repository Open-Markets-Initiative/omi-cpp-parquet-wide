#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Market Participant State
struct MarketParticipantState {

    static constexpr auto name = "market_participant_state";
    static constexpr auto nullable = true;

    MarketParticipantState() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Active"; }
        if (value == "E") { return "Excused"; }
        if (value == "W") { return "Withdrawn"; }
        if (value == "S") { return "Suspended"; }
        if (value == "D") { return "Deleted"; }
        return sanitize(value);
    }

    // set market_participant_state
    void set(const char* value) {
        data = translate(value);
    }

    // set market_participant_state
    void set(const std::string& value) {
        data = translate(value);
    }

    // set market_participant_state
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset market_participant_state field
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

    // append market_participant_state
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // market_participant_state schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}