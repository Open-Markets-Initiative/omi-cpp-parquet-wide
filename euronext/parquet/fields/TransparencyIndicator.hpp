#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Transparency Indicator
struct TransparencyIndicator {

    static constexpr auto name = "transparency_indicator";
    static constexpr auto nullable = true;

    TransparencyIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest transparency_indicator record field
    void reset() {
        data.reset();
    }

    // append transparency_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // transparency_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}