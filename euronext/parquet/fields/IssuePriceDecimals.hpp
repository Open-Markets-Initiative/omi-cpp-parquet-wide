#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Issue Price Decimals
struct IssuePriceDecimals {

    static constexpr auto name = "issue_price_decimals";
    static constexpr auto nullable = true;

    IssuePriceDecimals() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest issue_price_decimals record field
    void reset() {
        data.reset();
    }

    // append issue_price_decimals
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // issue_price_decimals arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}