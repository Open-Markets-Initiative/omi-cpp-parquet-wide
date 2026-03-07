#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Leg Ratio Qty
struct LegRatioQty {

    static constexpr auto name = "leg_ratio_qty";
    static constexpr auto nullable = true;

    LegRatioQty() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest leg_ratio_qty record field
    void reset() {
        data.reset();
    }

    // append leg_ratio_qty
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // leg_ratio_qty arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}