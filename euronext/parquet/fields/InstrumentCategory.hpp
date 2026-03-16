#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Instrument Category
struct InstrumentCategory {

    static constexpr auto name = "instrument_category";
    static constexpr auto nullable = true;

    InstrumentCategory() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest instrument_category record field
    void reset() {
        data.reset();
    }

    // append instrument_category
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // instrument_category arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}