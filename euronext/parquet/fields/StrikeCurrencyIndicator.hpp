#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Strike Currency Indicator
struct StrikeCurrencyIndicator {

    static constexpr auto name = "strike_currency_indicator";
    static constexpr auto nullable = true;

    StrikeCurrencyIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest strike_currency_indicator record field
    void reset() {
        data.reset();
    }

    // append strike_currency_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // strike_currency_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}