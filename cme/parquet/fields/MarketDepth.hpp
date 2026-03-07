#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Market Depth
struct MarketDepth {

    static constexpr auto name = "market_depth";
    static constexpr auto nullable = true;

    MarketDepth() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest market_depth record field
    void reset() {
        data.reset();
    }

    // append market_depth
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // market_depth arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}