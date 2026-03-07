#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Aggressor Side
struct AggressorSide {

    static constexpr auto name = "aggressor_side";
    static constexpr auto nullable = true;

    AggressorSide() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest aggressor_side record field
    void reset() {
        data.reset();
    }

    // append aggressor_side
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // aggressor_side arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}