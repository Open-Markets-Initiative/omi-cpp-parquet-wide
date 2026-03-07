#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Market Maker Mode
struct MarketMakerMode {

    static constexpr auto name = "market_maker_mode";
    static constexpr auto nullable = true;

    MarketMakerMode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "N") { return "Normal"; }
        if (value == "P") { return "Passive"; }
        if (value == "S") { return "Syndicate"; }
        if (value == "R") { return "Pre Syndicate"; }
        if (value == "L") { return "Penalty"; }
        return sanitize(value);
    }

    // set market_maker_mode
    void set(const char* value) {
        data = translate(value);
    }

    // set market_maker_mode
    void set(const std::string& value) {
        data = translate(value);
    }

    // set market_maker_mode
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset market_maker_mode field
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

    // append market_maker_mode
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // market_maker_mode schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}