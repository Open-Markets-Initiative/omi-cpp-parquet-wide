#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Price Multiplier Decimals
struct PriceMultiplierDecimals {

    static constexpr auto name = "price_multiplier_decimals";
    static constexpr auto nullable = true;

    PriceMultiplierDecimals() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest price_multiplier_decimals record field
    void reset() {
        data.reset();
    }

    // append price_multiplier_decimals
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // price_multiplier_decimals arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}