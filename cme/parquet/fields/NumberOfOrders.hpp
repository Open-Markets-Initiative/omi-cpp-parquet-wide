#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Number Of Orders
struct NumberOfOrders {

    static constexpr auto name = "number_of_orders";
    static constexpr auto nullable = true;

    NumberOfOrders() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest number_of_orders record field
    void reset() {
        data.reset();
    }

    // append number_of_orders
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // number_of_orders arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}