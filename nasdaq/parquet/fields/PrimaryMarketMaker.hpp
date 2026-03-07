#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Primary Market Maker
struct PrimaryMarketMaker {

    static constexpr auto name = "primary_market_maker";
    static constexpr auto nullable = true;

    PrimaryMarketMaker() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "Y") { return "Primary"; }
        if (value == "N") { return "Non Primary"; }
        return sanitize(value);
    }

    // set primary_market_maker
    void set(const char* value) {
        data = translate(value);
    }

    // set primary_market_maker
    void set(const std::string& value) {
        data = translate(value);
    }

    // set primary_market_maker
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset primary_market_maker field
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

    // append primary_market_maker
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // primary_market_maker schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}