#pragma once

#include <optional>
#include <string>
#include <algorithm>

#include "arrow/api.h"

namespace euronext {

// field: Block Trade Code
struct BlockTradeCode {

    static constexpr auto name = "block_trade_code";
    static constexpr auto nullable = true;

    BlockTradeCode() = default;

    // translate raw value to enum name
    static std::string translate(const std::string& value) {
        if (value == "B") { return "Block Trade"; }
        if (value == "N") { return "Regulartradeor Negotiateddeal"; }
        if (value == "-") { return "Undefined"; }
        return sanitize(value);
    }

    // set block_trade_code
    void set(const char* value) {
        data = translate(value);
    }

    // set block_trade_code
    void set(const std::string& value) {
        data = translate(value);
    }

    // set block_trade_code
    void set(const char value) {
        data = translate(std::string(1, value));
    }

    // reset block_trade_code field
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

    // append block_trade_code
    auto append(arrow::StringBuilder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // block_trade_code schema field
    static auto column() {
        return arrow::field(name, arrow::utf8(), nullable);
    }

    std::optional<std::string> data;
};

}