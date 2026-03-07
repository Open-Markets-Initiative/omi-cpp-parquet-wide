#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Decay Start Date
struct DecayStartDate {

    static constexpr auto name = "decay_start_date";
    static constexpr auto nullable = true;

    DecayStartDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest decay_start_date record field
    void reset() {
        data.reset();
    }

    // append decay_start_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // decay_start_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}