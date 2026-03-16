#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Price Decimals Optional
struct PriceDecimalsOptional {

    static constexpr auto name = "price_decimals_optional";
    static constexpr auto nullable = true;

    PriceDecimalsOptional() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest price_decimals_optional record field
    void reset() {
        data.reset();
    }

    // append price_decimals_optional
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // price_decimals_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}