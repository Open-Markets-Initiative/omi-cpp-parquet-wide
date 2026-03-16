#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Maximum Decimals In Quantity
struct MaximumDecimalsInQuantity {

    static constexpr auto name = "maximum_decimals_in_quantity";
    static constexpr auto nullable = true;

    MaximumDecimalsInQuantity() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest maximum_decimals_in_quantity record field
    void reset() {
        data.reset();
    }

    // append maximum_decimals_in_quantity
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // maximum_decimals_in_quantity arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}