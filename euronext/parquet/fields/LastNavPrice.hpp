#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Last Nav Price
struct LastNavPrice {

    static constexpr auto name = "last_nav_price";
    static constexpr auto nullable = true;

    LastNavPrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest last_nav_price record field
    void reset() {
        data.reset();
    }

    // append last_nav_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // last_nav_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}