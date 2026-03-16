#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Evaluated Price
struct EvaluatedPrice {

    static constexpr auto name = "evaluated_price";
    static constexpr auto nullable = true;

    EvaluatedPrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest evaluated_price record field
    void reset() {
        data.reset();
    }

    // append evaluated_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // evaluated_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}