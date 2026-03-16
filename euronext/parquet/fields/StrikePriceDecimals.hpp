#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Strike Price Decimals
struct StrikePriceDecimals {

    static constexpr auto name = "strike_price_decimals";
    static constexpr auto nullable = true;

    StrikePriceDecimals() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest strike_price_decimals record field
    void reset() {
        data.reset();
    }

    // append strike_price_decimals
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // strike_price_decimals arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}