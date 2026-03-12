#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Best Offer Size
struct BestOfferSize {

    static constexpr auto name = "best_offer_size";
    static constexpr auto nullable = true;

    BestOfferSize() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest best_offer_size record field
    void reset() {
        data.reset();
    }

    // append best_offer_size
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // best_offer_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}