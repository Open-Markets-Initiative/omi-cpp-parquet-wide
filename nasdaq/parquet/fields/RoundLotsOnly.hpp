#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Round Lots Only
struct RoundLotsOnly {

    static constexpr auto name = "round_lots_only";
    static constexpr auto nullable = true;

    RoundLotsOnly() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Y") { return "Yes"; }
        if (value == "N") { return "No"; }
        return sanitize(value);
    }

    // set round_lots_only
    void set(const char* value) {
        data = translate(value);
    }

    // set round_lots_only
    void set(const std::string& value) {
        data = translate(value);
    }

    // set round_lots_only
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset round_lots_only field
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

    // append round_lots_only
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // round_lots_only schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}