#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Nav Bid Price
struct NavBidPrice {

    static constexpr auto name = "nav_bid_price";
    static constexpr auto nullable = true;

    NavBidPrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest nav_bid_price record field
    void reset() {
        data.reset();
    }

    // append nav_bid_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // nav_bid_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}