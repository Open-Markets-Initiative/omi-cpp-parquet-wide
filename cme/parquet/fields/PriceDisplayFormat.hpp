#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Price Display Format
struct PriceDisplayFormat {

    static constexpr auto name = "price_display_format";
    static constexpr auto nullable = true;

    PriceDisplayFormat() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest price_display_format record field
    void reset() {
        data.reset();
    }

    // append price_display_format
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // price_display_format arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}