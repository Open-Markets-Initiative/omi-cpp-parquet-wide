#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Last Trading Date
struct LastTradingDate {

    static constexpr auto name = "last_trading_date";
    static constexpr auto nullable = true;

    LastTradingDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest last_trading_date record field
    void reset() {
        data.reset();
    }

    // append last_trading_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // last_trading_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}