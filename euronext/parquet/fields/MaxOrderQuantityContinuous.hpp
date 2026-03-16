#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Max Order Quantity Continuous
struct MaxOrderQuantityContinuous {

    static constexpr auto name = "max_order_quantity_continuous";
    static constexpr auto nullable = true;

    MaxOrderQuantityContinuous() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest max_order_quantity_continuous record field
    void reset() {
        data.reset();
    }

    // append max_order_quantity_continuous
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // max_order_quantity_continuous arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}