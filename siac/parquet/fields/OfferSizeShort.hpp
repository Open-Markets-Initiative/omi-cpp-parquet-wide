#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Offer Size Short
struct OfferSizeShort {

    static constexpr auto name = "offer_size_short";
    static constexpr auto nullable = true;

    OfferSizeShort() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest offer_size_short record field
    void reset() {
        data.reset();
    }

    // append offer_size_short
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // offer_size_short arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}