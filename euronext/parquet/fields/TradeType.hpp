#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Trade Type
struct TradeType {

    static constexpr auto name = "trade_type";
    static constexpr auto nullable = true;

    TradeType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest trade_type record field
    void reset() {
        data.reset();
    }

    // append trade_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trade_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}