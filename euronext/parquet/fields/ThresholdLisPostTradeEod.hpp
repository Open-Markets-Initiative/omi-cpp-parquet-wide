#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Threshold Lis Post Trade Eod
struct ThresholdLisPostTradeEod {

    static constexpr auto name = "threshold_lis_post_trade_eod";
    static constexpr auto nullable = true;

    ThresholdLisPostTradeEod() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest threshold_lis_post_trade_eod record field
    void reset() {
        data.reset();
    }

    // append threshold_lis_post_trade_eod
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // threshold_lis_post_trade_eod arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}