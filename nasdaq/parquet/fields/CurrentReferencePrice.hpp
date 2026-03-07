#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// field: Current Reference Price
struct CurrentReferencePrice {

    static constexpr auto name = "current_reference_price";
    static constexpr auto nullable = true;
    static constexpr auto precision = 10;
    static constexpr auto scale = 4;
    static constexpr auto scalar = 10000;

    CurrentReferencePrice() = default;

    // current_reference_price schema field
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

    // append current_reference_price
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // current_reference_price schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}