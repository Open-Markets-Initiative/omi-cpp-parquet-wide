#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Low Price
struct LowPrice {

    static constexpr auto name = "low_price";
    static constexpr auto nullable = true;

    LowPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest low_price record field
    void reset() {
        data.reset();
    }

    // append low_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // low_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}