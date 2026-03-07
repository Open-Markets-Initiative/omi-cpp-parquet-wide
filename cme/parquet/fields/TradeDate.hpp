#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Trade Date
struct TradeDate {

    static constexpr auto name = "trade_date";
    static constexpr auto nullable = true;

    TradeDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest trade_date record field
    void reset() {
        data.reset();
    }

    // append trade_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trade_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}