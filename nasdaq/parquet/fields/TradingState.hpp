#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace nasdaq {

// field: Trading State
struct TradingState {

    static constexpr auto name = "trading_state";
    static constexpr auto nullable = true;

    TradingState() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "H") { return "Halted"; }
        if (value == "P") { return "Paused"; }
        if (value == "Q") { return "Quotation Only Period"; }
        if (value == "T") { return "Trading"; }
        return sanitize(value);
    }

    // set trading_state
    void set(const char* value) {
        data = translate(value);
    }

    // set trading_state
    void set(const std::string& value) {
        data = translate(value);
    }

    // set trading_state
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset trading_state field
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

    // append trading_state
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trading_state schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}