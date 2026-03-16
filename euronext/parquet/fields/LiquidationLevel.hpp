#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Liquidation Level
struct LiquidationLevel {

    static constexpr auto name = "liquidation_level";
    static constexpr auto nullable = true;

    LiquidationLevel() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest liquidation_level record field
    void reset() {
        data.reset();
    }

    // append liquidation_level
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // liquidation_level arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}