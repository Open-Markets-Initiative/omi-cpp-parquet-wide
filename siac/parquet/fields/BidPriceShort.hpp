#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// field: Bid Price Short
struct BidPriceShort {

    static constexpr auto name = "bid_price_short";
    static constexpr auto nullable = true;
    static constexpr auto precision = 5;
    static constexpr auto scale = 2;
    static constexpr auto scalar = 100;

    BidPriceShort() = default;

    // bid_price_short schema field
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

    // append bid_price_short
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bid_price_short schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}