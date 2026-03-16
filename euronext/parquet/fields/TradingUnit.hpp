#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Trading Unit
struct TradingUnit {

    static constexpr auto name = "trading_unit";
    static constexpr auto nullable = true;

    TradingUnit() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest trading_unit record field
    void reset() {
        data.reset();
    }

    // append trading_unit
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trading_unit arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}