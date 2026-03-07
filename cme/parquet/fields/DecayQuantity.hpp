#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Decay Quantity
struct DecayQuantity {

    static constexpr auto name = "decay_quantity";
    static constexpr auto nullable = true;

    DecayQuantity() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest decay_quantity record field
    void reset() {
        data.reset();
    }

    // append decay_quantity
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // decay_quantity arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}