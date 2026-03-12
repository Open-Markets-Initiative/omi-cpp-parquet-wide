#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Underlying Price
struct UnderlyingPrice {

    static constexpr auto name = "underlying_price";
    static constexpr auto nullable = true;

    UnderlyingPrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest underlying_price record field
    void reset() {
        data.reset();
    }

    // append underlying_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}