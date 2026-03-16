#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Strike Price Decimals Ratio
struct StrikePriceDecimalsRatio {

    static constexpr auto name = "strike_price_decimals_ratio";
    static constexpr auto nullable = true;

    StrikePriceDecimalsRatio() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest strike_price_decimals_ratio record field
    void reset() {
        data.reset();
    }

    // append strike_price_decimals_ratio
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // strike_price_decimals_ratio arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}