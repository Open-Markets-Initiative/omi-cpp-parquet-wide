#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Max Order Amount Call
struct MaxOrderAmountCall {

    static constexpr auto name = "max_order_amount_call";
    static constexpr auto nullable = true;

    MaxOrderAmountCall() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest max_order_amount_call record field
    void reset() {
        data.reset();
    }

    // append max_order_amount_call
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // max_order_amount_call arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}