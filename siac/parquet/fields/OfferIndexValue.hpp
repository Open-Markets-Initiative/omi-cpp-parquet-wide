#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Offer Index Value
struct OfferIndexValue {

    static constexpr auto name = "offer_index_value";
    static constexpr auto nullable = true;

    OfferIndexValue() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest offer_index_value record field
    void reset() {
        data.reset();
    }

    // append offer_index_value
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // offer_index_value arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}