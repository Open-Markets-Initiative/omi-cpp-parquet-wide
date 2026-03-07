#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Min Trade Vol
struct MinTradeVol {

    static constexpr auto name = "min_trade_vol";
    static constexpr auto nullable = true;

    MinTradeVol() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest min_trade_vol record field
    void reset() {
        data.reset();
    }

    // append min_trade_vol
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // min_trade_vol arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}