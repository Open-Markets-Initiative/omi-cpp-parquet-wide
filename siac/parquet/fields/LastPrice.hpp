#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Last Price
struct LastPrice {

    static constexpr auto name = "last_price";
    static constexpr auto nullable = true;

    LastPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest last_price record field
    void reset() {
        data.reset();
    }

    // append last_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // last_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}