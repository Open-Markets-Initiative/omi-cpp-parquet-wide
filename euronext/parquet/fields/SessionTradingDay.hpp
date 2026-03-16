#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Session Trading Day
struct SessionTradingDay {

    static constexpr auto name = "session_trading_day";
    static constexpr auto nullable = true;

    SessionTradingDay() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest session_trading_day record field
    void reset() {
        data.reset();
    }

    // append session_trading_day
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // session_trading_day arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}