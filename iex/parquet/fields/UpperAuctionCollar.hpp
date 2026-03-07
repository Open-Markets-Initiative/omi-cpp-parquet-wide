#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// field: Upper Auction Collar
struct UpperAuctionCollar {

    static constexpr auto name = "upper_auction_collar";
    static constexpr auto nullable = true;
    static constexpr auto precision = 18;
    static constexpr auto scale = 4;
    static constexpr auto scalar = 10000;

    UpperAuctionCollar() = default;

    // upper_auction_collar schema field
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

    // append upper_auction_collar
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // upper_auction_collar schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}