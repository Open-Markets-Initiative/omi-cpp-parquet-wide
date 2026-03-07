#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// field: Lower Price Range Collar
struct LowerPriceRangeCollar {

    static constexpr auto name = "lower_price_range_collar";
    static constexpr auto nullable = true;
    static constexpr auto precision = 10;
    static constexpr auto scale = 4;
    static constexpr auto scalar = 10000;

    LowerPriceRangeCollar() = default;

    // lower_price_range_collar schema field
    void reset() {
        data.reset();
    }

    void set(const double value) {
        data = value * scalar;
    }

    [[nodiscard]] std::optional<double> display() const {
        std::optional<double> result;
        if (data) {
            result = static_cast<double>(data.value()) / scalar;
        }

        return result;
    }

    // append lower_price_range_collar
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // lower_price_range_collar schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}