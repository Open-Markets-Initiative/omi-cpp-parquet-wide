#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Instrument Event Date
struct InstrumentEventDate {

    static constexpr auto name = "instrument_event_date";
    static constexpr auto nullable = true;

    InstrumentEventDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest instrument_event_date record field
    void reset() {
        data.reset();
    }

    // append instrument_event_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // instrument_event_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}