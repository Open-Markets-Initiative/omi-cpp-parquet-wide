#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Guarantee Indicator
struct GuaranteeIndicator {

    static constexpr auto name = "guarantee_indicator";
    static constexpr auto nullable = true;

    GuaranteeIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest guarantee_indicator record field
    void reset() {
        data.reset();
    }

    // append guarantee_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // guarantee_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}