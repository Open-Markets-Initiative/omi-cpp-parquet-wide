#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// High Price
struct HighPrice {

    static constexpr auto name = "high_price";
    static constexpr auto nullable = true;

    HighPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest high_price record field
    void reset() {
        data.reset();
    }

    // append high_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // high_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}