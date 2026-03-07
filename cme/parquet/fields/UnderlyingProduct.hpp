#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Underlying Product
struct UnderlyingProduct {

    static constexpr auto name = "underlying_product";
    static constexpr auto nullable = true;

    UnderlyingProduct() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest underlying_product record field
    void reset() {
        data.reset();
    }

    // append underlying_product
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_product arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}