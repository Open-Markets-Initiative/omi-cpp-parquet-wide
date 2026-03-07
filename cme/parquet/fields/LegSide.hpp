#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Leg Side
struct LegSide {

    static constexpr auto name = "leg_side";
    static constexpr auto nullable = true;

    LegSide() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest leg_side record field
    void reset() {
        data.reset();
    }

    // append leg_side
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // leg_side arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}