#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// field: Min Price Increment Amount
struct MinPriceIncrementAmount {

    static constexpr auto name = "min_price_increment_amount";
    static constexpr auto nullable = true;
    static constexpr auto precision = 18;
    static constexpr auto scale = 7;
    static constexpr auto scalar = 10000000;

    MinPriceIncrementAmount() = default;

    // min_price_increment_amount schema field
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

    // append min_price_increment_amount
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // min_price_increment_amount schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}