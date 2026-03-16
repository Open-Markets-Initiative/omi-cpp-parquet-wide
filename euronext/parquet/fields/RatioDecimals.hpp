#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Ratio Decimals
struct RatioDecimals {

    static constexpr auto name = "ratio_decimals";
    static constexpr auto nullable = true;

    RatioDecimals() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest ratio_decimals record field
    void reset() {
        data.reset();
    }

    // append ratio_decimals
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ratio_decimals arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}