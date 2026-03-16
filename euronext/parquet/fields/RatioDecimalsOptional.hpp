#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Ratio Decimals Optional
struct RatioDecimalsOptional {

    static constexpr auto name = "ratio_decimals_optional";
    static constexpr auto nullable = true;

    RatioDecimalsOptional() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest ratio_decimals_optional record field
    void reset() {
        data.reset();
    }

    // append ratio_decimals_optional
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ratio_decimals_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}