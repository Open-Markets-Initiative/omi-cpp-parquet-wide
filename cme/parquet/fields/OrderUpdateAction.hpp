#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Order Update Action
struct OrderUpdateAction {

    static constexpr auto name = "order_update_action";
    static constexpr auto nullable = true;

    OrderUpdateAction() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest order_update_action record field
    void reset() {
        data.reset();
    }

    // append order_update_action
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // order_update_action arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}