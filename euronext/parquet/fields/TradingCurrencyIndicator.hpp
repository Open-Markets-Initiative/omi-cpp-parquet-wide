#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Trading Currency Indicator
struct TradingCurrencyIndicator {

    static constexpr auto name = "trading_currency_indicator";
    static constexpr auto nullable = true;

    TradingCurrencyIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest trading_currency_indicator record field
    void reset() {
        data.reset();
    }

    // append trading_currency_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trading_currency_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}