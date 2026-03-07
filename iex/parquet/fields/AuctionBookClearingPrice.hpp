#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// field: Auction Book Clearing Price
struct AuctionBookClearingPrice {

    static constexpr auto name = "auction_book_clearing_price";
    static constexpr auto nullable = true;
    static constexpr auto precision = 18;
    static constexpr auto scale = 4;
    static constexpr auto scalar = 10000;

    AuctionBookClearingPrice() = default;

    // auction_book_clearing_price schema field
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

    // append auction_book_clearing_price
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // auction_book_clearing_price schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}