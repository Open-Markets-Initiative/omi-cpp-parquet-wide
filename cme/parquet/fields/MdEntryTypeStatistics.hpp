#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace cme {

// field: Md Entry Type Statistics
struct MdEntryTypeStatistics {

    static constexpr auto name = "md_entry_type_statistics";
    static constexpr auto nullable = true;

    MdEntryTypeStatistics() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "4") { return "Open Price"; }
        if (value == "7") { return "High Trade"; }
        if (value == "8") { return "Low Trade"; }
        if (value == "N") { return "Highest Bid"; }
        if (value == "O") { return "Lowest Offer"; }
        return sanitize(value);
    }

    // set md_entry_type_statistics
    void set(const char* value) {
        data = translate(value);
    }

    // set md_entry_type_statistics
    void set(const std::string& value) {
        data = translate(value);
    }

    // set md_entry_type_statistics
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset md_entry_type_statistics field
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

    // append md_entry_type_statistics
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_entry_type_statistics schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}