#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Price Level
struct MdPriceLevel {

    static constexpr auto name = "md_price_level";
    static constexpr auto nullable = true;

    MdPriceLevel() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest md_price_level record field
    void reset() {
        data.reset();
    }

    // append md_price_level
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_price_level arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}