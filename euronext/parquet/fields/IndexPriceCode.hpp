#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Index Price Code
struct IndexPriceCode {

    static constexpr auto name = "index_price_code";
    static constexpr auto nullable = true;

    IndexPriceCode() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest index_price_code record field
    void reset() {
        data.reset();
    }

    // append index_price_code
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // index_price_code arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}