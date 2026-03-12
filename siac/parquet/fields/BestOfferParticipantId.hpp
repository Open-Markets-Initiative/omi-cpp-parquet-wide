#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace siac {

// field: Best Offer Participant Id
struct BestOfferParticipantId {

    static constexpr auto name = "best_offer_participant_id";
    static constexpr auto nullable = true;

    BestOfferParticipantId() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "A") { return "Nyse American"; }
        if (value == "B") { return "Boston Options Exchange"; }
        if (value == "C") { return "Cboe Options Exchange"; }
        if (value == "D") { return "Miax Emerald"; }
        if (value == "E") { return "Cboe Edgx Options"; }
        if (value == "H") { return "Nasdaq Gemx"; }
        if (value == "I") { return "Nasdaq Ise"; }
        if (value == "J") { return "Nasdaq Mrx"; }
        if (value == "M") { return "Miami International Securities Exchange"; }
        if (value == "N") { return "Nyse Arca"; }
        if (value == "O") { return "Options Price Reporting Authority"; }
        if (value == "P") { return "Miax Pearl"; }
        if (value == "Q") { return "Nasdaq Options Market"; }
        if (value == "T") { return "Nasdaq Bx Options"; }
        if (value == "W") { return "Cboe C 2 Options"; }
        if (value == "X") { return "Nasdaq Phlx"; }
        if (value == "Z") { return "Cboe Bzx Options Exchange"; }
        return sanitize(value);
    }

    // set best_offer_participant_id
    void set(const char* value) {
        data = translate(value);
    }

    // set best_offer_participant_id
    void set(const std::string& value) {
        data = translate(value);
    }

    // set best_offer_participant_id
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset best_offer_participant_id field
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

    // append best_offer_participant_id
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // best_offer_participant_id schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}