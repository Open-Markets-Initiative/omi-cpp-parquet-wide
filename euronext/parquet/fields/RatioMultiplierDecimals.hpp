#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Ratio Multiplier Decimals
struct RatioMultiplierDecimals {

    static constexpr auto name = "ratio_multiplier_decimals";
    static constexpr auto nullable = true;

    RatioMultiplierDecimals() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest ratio_multiplier_decimals record field
    void reset() {
        data.reset();
    }

    // append ratio_multiplier_decimals
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ratio_multiplier_decimals arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}