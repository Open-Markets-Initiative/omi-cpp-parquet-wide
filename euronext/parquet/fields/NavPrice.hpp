#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Nav Price
struct NavPrice {

    static constexpr auto name = "nav_price";
    static constexpr auto nullable = true;

    NavPrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest nav_price record field
    void reset() {
        data.reset();
    }

    // append nav_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // nav_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}