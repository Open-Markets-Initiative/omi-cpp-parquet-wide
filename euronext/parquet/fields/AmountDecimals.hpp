#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Amount Decimals
struct AmountDecimals {

    static constexpr auto name = "amount_decimals";
    static constexpr auto nullable = true;

    AmountDecimals() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest amount_decimals record field
    void reset() {
        data.reset();
    }

    // append amount_decimals
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // amount_decimals arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}