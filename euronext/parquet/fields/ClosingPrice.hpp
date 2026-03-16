#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Closing Price
struct ClosingPrice {

    static constexpr auto name = "closing_price";
    static constexpr auto nullable = true;

    ClosingPrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest closing_price record field
    void reset() {
        data.reset();
    }

    // append closing_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // closing_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}