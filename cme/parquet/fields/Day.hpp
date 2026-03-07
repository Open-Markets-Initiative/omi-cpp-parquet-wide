#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Day
struct Day {

    static constexpr auto name = "day";
    static constexpr auto nullable = true;

    Day() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest day record field
    void reset() {
        data.reset();
    }

    // append day
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // day arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}