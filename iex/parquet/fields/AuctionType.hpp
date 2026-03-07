#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace iex {

// field: Auction Type
struct AuctionType {

    static constexpr auto name = "auction_type";
    static constexpr auto nullable = true;

    AuctionType() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "O") { return "Opening Auction"; }
        if (value == "C") { return "Closing Auction"; }
        if (value == "I") { return "Ipo Auction"; }
        if (value == "H") { return "Halt Auction"; }
        if (value == "V") { return "Volatility Auction"; }
        return sanitize(value);
    }

    // set auction_type
    void set(const char* value) {
        data = translate(value);
    }

    // set auction_type
    void set(const std::string& value) {
        data = translate(value);
    }

    // set auction_type
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset auction_type field
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

    // append auction_type
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // auction_type schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}