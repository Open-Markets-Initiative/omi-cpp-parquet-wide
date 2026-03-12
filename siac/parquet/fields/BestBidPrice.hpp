#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Best Bid Price
struct BestBidPrice {

    static constexpr auto name = "best_bid_price";
    static constexpr auto nullable = true;

    BestBidPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest best_bid_price record field
    void reset() {
        data.reset();
    }

    // append best_bid_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // best_bid_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}