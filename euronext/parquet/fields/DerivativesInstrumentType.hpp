#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Derivatives Instrument Type
struct DerivativesInstrumentType {

    static constexpr auto name = "derivatives_instrument_type";
    static constexpr auto nullable = true;

    DerivativesInstrumentType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest derivatives_instrument_type record field
    void reset() {
        data.reset();
    }

    // append derivatives_instrument_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // derivatives_instrument_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}