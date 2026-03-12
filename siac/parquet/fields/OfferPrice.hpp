#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Offer Price
struct OfferPrice {

    static constexpr auto name = "offer_price";
    static constexpr auto nullable = true;

    OfferPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest offer_price record field
    void reset() {
        data.reset();
    }

    // append offer_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // offer_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}