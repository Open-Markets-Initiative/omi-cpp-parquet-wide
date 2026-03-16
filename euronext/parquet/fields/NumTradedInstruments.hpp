#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Num Traded Instruments
struct NumTradedInstruments {

    static constexpr auto name = "num_traded_instruments";
    static constexpr auto nullable = true;

    NumTradedInstruments() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest num_traded_instruments record field
    void reset() {
        data.reset();
    }

    // append num_traded_instruments
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // num_traded_instruments arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}