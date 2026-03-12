#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Best Offer Price
struct BestOfferPrice {

    static constexpr auto name = "best_offer_price";
    static constexpr auto nullable = true;

    BestOfferPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest best_offer_price record field
    void reset() {
        data.reset();
    }

    // append best_offer_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // best_offer_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}