#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace iex {

// field: Trading Status
struct TradingStatus {

    static constexpr auto name = "trading_status";
    static constexpr auto nullable = true;

    TradingStatus() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "H") { return "Trading Halted Across All Us Equity Markets"; }
        if (value == "O") { return "Trading Halt Released Into An Order Acceptance Period On Iex"; }
        if (value == "P") { return "Trading Paused And Order Acceptance Period On Iex"; }
        if (value == "T") { return "Trading On Iex"; }
        return sanitize(value);
    }

    // set trading_status
    void set(const char* value) {
        data = translate(value);
    }

    // set trading_status
    void set(const std::string& value) {
        data = translate(value);
    }

    // set trading_status
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset trading_status field
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

    // append trading_status
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trading_status schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}