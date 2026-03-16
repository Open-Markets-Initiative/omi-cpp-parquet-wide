#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Liquid Instrument Indicator
struct LiquidInstrumentIndicator {

    static constexpr auto name = "liquid_instrument_indicator";
    static constexpr auto nullable = true;

    LiquidInstrumentIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest liquid_instrument_indicator record field
    void reset() {
        data.reset();
    }

    // append liquid_instrument_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // liquid_instrument_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}