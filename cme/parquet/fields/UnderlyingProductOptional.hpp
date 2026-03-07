#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Underlying Product Optional
struct UnderlyingProductOptional {

    static constexpr auto name = "underlying_product_optional";
    static constexpr auto nullable = true;

    UnderlyingProductOptional() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest underlying_product_optional record field
    void reset() {
        data.reset();
    }

    // append underlying_product_optional
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_product_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}