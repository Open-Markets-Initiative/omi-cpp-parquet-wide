#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Quantity Decimals
struct QuantityDecimals {

    static constexpr auto name = "quantity_decimals";
    static constexpr auto nullable = true;

    QuantityDecimals() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest quantity_decimals record field
    void reset() {
        data.reset();
    }

    // append quantity_decimals
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // quantity_decimals arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}