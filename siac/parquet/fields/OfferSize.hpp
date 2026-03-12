#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Offer Size
struct OfferSize {

    static constexpr auto name = "offer_size";
    static constexpr auto nullable = true;

    OfferSize() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest offer_size record field
    void reset() {
        data.reset();
    }

    // append offer_size
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // offer_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}