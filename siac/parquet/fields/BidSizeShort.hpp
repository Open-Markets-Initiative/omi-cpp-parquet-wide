#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Bid Size Short
struct BidSizeShort {

    static constexpr auto name = "bid_size_short";
    static constexpr auto nullable = true;

    BidSizeShort() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest bid_size_short record field
    void reset() {
        data.reset();
    }

    // append bid_size_short
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bid_size_short arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}