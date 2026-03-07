#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Md Entry Type 
struct MdEntryType {

    static constexpr auto name = "md_entry_type_";
    static constexpr auto nullable = true;

    MdEntryType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "0") { return "Bid"; }
        if (value == "1") { return "Offer"; }
        if (value == "2") { return "Trade"; }
        if (value == "4") { return "Open Price"; }
        if (value == "6") { return "Settlement Price"; }
        if (value == "7") { return "Trading Session High Price"; }
        if (value == "8") { return "Trading Session Low Price"; }
        if (value == "B") { return "Cleared Volume"; }
        if (value == "C") { return "Open Interest"; }
        if (value == "E") { return "Implied Bid"; }
        if (value == "F") { return "Implied Offer"; }
        if (value == "J") { return "Book Reset"; }
        if (value == "N") { return "Session High Bid"; }
        if (value == "O") { return "Session Low Offer"; }
        if (value == "W") { return "Fixing Price"; }
        if (value == "e") { return "Electronic Volume"; }
        if (value == "g") { return "Threshold Limitsand Price Band Variation"; }
        return sanitize(value);
    }

    // set md_entry_type_
    void set(const char* value) {
        data = translate(value);
    }

    // set md_entry_type_
    void set(const std::string& value) {
        data = translate(value);
    }

    // set md_entry_type_
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset md_entry_type_ field
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

    // append md_entry_type_
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_entry_type_ schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}