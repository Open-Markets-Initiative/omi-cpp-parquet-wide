#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Trade Identifier
struct TradeIdentifier {

    static constexpr auto name = "trade_identifier";
    static constexpr auto nullable = true;

    TradeIdentifier() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest trade_identifier record field
    void reset() {
        data.reset();
    }

    // append trade_identifier
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trade_identifier arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}