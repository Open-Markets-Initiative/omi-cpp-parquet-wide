#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Threshold Lis Post Trade 120mn
struct ThresholdLisPostTrade120Mn {

    static constexpr auto name = "threshold_lis_post_trade_120mn";
    static constexpr auto nullable = true;

    ThresholdLisPostTrade120Mn() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest threshold_lis_post_trade_120mn record field
    void reset() {
        data.reset();
    }

    // append threshold_lis_post_trade_120mn
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // threshold_lis_post_trade_120mn arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}