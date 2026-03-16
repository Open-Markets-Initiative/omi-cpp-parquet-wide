#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Reference Price Origin In Trading Interruption
struct ReferencePriceOriginInTradingInterruption {

    static constexpr auto name = "reference_price_origin_in_trading_interruption";
    static constexpr auto nullable = true;

    ReferencePriceOriginInTradingInterruption() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest reference_price_origin_in_trading_interruption record field
    void reset() {
        data.reset();
    }

    // append reference_price_origin_in_trading_interruption
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reference_price_origin_in_trading_interruption arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}