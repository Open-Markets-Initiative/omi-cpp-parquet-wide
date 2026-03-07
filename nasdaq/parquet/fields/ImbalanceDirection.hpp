#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Imbalance Direction
struct ImbalanceDirection {

    static constexpr auto name = "imbalance_direction";
    static constexpr auto nullable = true;

    ImbalanceDirection() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "B") { return "Buy"; }
        if (value == "S") { return "Sell"; }
        if (value == "N") { return "None"; }
        if (value == "O") { return "Insufficient Orders"; }
        if (value == "P") { return "Paused"; }
        return sanitize(value);
    }

    // set imbalance_direction
    void set(const char* value) {
        data = translate(value);
    }

    // set imbalance_direction
    void set(const std::string& value) {
        data = translate(value);
    }

    // set imbalance_direction
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset imbalance_direction field
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

    // append imbalance_direction
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // imbalance_direction schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}