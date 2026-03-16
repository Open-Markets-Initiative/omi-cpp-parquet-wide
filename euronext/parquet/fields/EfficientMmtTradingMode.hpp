#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Efficient Mmt Trading Mode
struct EfficientMmtTradingMode {

    static constexpr auto name = "efficient_mmt_trading_mode";
    static constexpr auto nullable = true;

    EfficientMmtTradingMode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "1") { return "Undefined Auctionequal Uncrossing"; }
        if (value == "2") { return "Continuous Trading"; }
        if (value == "3") { return "At Market Close Trading"; }
        if (value == "4") { return "Outof Main Session Trading"; }
        if (value == "5") { return "Trade Reporting On Exchange"; }
        if (value == "6") { return "Trade Reporting Off Exchange"; }
        if (value == "7") { return "Trade Reporting Systematic Internaliser"; }
        if (value == "I") { return "Scheduled Intraday Auctionequal Uncrossing"; }
        if (value == "K") { return "Scheduled Closing Auctionequal Uncrossing"; }
        if (value == "O") { return "Scheduled Opening Auctionequal Uncrossing"; }
        if (value == "U") { return "Unscheduled Auctionequal Uncrossing"; }
        return sanitize(value);
    }

    // set efficient_mmt_trading_mode
    void set(const char* value) {
        data = translate(value);
    }

    // set efficient_mmt_trading_mode
    void set(const std::string& value) {
        data = translate(value);
    }

    // set efficient_mmt_trading_mode
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset efficient_mmt_trading_mode field
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

    // append efficient_mmt_trading_mode
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // efficient_mmt_trading_mode schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}