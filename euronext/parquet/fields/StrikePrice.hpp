#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Strike Price
struct StrikePrice {

    static constexpr auto name = "strike_price";
    static constexpr auto nullable = true;

    StrikePrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest strike_price record field
    void reset() {
        data.reset();
    }

    // append strike_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // strike_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}