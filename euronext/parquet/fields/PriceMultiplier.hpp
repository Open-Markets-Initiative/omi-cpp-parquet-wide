#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Price Multiplier
struct PriceMultiplier {

    static constexpr auto name = "price_multiplier";
    static constexpr auto nullable = true;

    PriceMultiplier() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest price_multiplier record field
    void reset() {
        data.reset();
    }

    // append price_multiplier
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // price_multiplier arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}