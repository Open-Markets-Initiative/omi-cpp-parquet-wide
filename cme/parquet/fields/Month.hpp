#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Month
struct Month {

    static constexpr auto name = "month";
    static constexpr auto nullable = true;

    Month() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest month record field
    void reset() {
        data.reset();
    }

    // append month
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // month arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}