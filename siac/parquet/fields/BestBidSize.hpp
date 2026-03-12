#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Best Bid Size
struct BestBidSize {

    static constexpr auto name = "best_bid_size";
    static constexpr auto nullable = true;

    BestBidSize() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest best_bid_size record field
    void reset() {
        data.reset();
    }

    // append best_bid_size
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // best_bid_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}