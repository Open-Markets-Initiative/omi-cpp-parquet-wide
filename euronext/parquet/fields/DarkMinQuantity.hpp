#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Dark Min Quantity
struct DarkMinQuantity {

    static constexpr auto name = "dark_min_quantity";
    static constexpr auto nullable = true;

    DarkMinQuantity() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest dark_min_quantity record field
    void reset() {
        data.reset();
    }

    // append dark_min_quantity
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // dark_min_quantity arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}