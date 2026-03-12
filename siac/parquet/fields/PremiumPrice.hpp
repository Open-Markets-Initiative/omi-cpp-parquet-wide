#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Premium Price
struct PremiumPrice {

    static constexpr auto name = "premium_price";
    static constexpr auto nullable = true;

    PremiumPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest premium_price record field
    void reset() {
        data.reset();
    }

    // append premium_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // premium_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}