#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Trading Reference Date
struct TradingReferenceDate {

    static constexpr auto name = "trading_reference_date";
    static constexpr auto nullable = true;

    TradingReferenceDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest trading_reference_date record field
    void reset() {
        data.reset();
    }

    // append trading_reference_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trading_reference_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}