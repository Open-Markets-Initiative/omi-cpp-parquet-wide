#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Market Segment Id
struct MarketSegmentId {

    static constexpr auto name = "market_segment_id";
    static constexpr auto nullable = true;

    MarketSegmentId() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest market_segment_id record field
    void reset() {
        data.reset();
    }

    // append market_segment_id
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // market_segment_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}