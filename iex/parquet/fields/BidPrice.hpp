#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// field: Bid Price
struct BidPrice {

    static constexpr auto name = "bid_price";
    static constexpr auto nullable = true;
    static constexpr auto precision = 18;
    static constexpr auto scale = 4;
    static constexpr auto scalar = 10000;

    BidPrice() = default;

    // bid_price schema field
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

    // append bid_price
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bid_price schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}