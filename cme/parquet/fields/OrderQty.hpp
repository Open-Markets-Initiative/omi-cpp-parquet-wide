#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Order Qty
struct OrderQty {

    static constexpr auto name = "order_qty";
    static constexpr auto nullable = true;

    OrderQty() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest order_qty record field
    void reset() {
        data.reset();
    }

    // append order_qty
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // order_qty arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}