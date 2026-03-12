#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Bid Size
struct BidSize {

    static constexpr auto name = "bid_size";
    static constexpr auto nullable = true;

    BidSize() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest bid_size record field
    void reset() {
        data.reset();
    }

    // append bid_size
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bid_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}