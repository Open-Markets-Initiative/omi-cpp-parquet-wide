#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Bid Price
struct BidPrice {

    static constexpr auto name = "bid_price";
    static constexpr auto nullable = true;

    BidPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest bid_price record field
    void reset() {
        data.reset();
    }

    // append bid_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bid_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}