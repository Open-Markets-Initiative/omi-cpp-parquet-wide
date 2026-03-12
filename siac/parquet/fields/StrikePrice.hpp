#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Strike Price
struct StrikePrice {

    static constexpr auto name = "strike_price";
    static constexpr auto nullable = true;

    StrikePrice() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest strike_price record field
    void reset() {
        data.reset();
    }

    // append strike_price
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // strike_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}