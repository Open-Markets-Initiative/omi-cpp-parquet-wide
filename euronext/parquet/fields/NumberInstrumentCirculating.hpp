#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Number Instrument Circulating
struct NumberInstrumentCirculating {

    static constexpr auto name = "number_instrument_circulating";
    static constexpr auto nullable = true;

    NumberInstrumentCirculating() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest number_instrument_circulating record field
    void reset() {
        data.reset();
    }

    // append number_instrument_circulating
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // number_instrument_circulating arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}