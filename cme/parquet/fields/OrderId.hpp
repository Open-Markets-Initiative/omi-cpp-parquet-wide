#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Order Id
struct OrderId {

    static constexpr auto name = "order_id";
    static constexpr auto nullable = true;

    OrderId() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest order_id record field
    void reset() {
        data.reset();
    }

    // append order_id
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // order_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}