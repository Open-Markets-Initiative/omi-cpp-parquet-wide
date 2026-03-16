#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Liquidation Time
struct LiquidationTime {

    static constexpr auto name = "liquidation_time";
    static constexpr auto nullable = true;

    LiquidationTime() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest liquidation_time record field
    void reset() {
        data.reset();
    }

    // append liquidation_time
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // liquidation_time arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}