#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Trade Id
struct TradeId {

    static constexpr auto name = "trade_id";
    static constexpr auto nullable = true;

    TradeId() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest trade_id record field
    void reset() {
        data.reset();
    }

    // append trade_id
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trade_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}