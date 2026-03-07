#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Short Sale Price Test Status
struct ShortSalePriceTestStatus {

    static constexpr auto name = "short_sale_price_test_status";
    static constexpr auto nullable = true;

    ShortSalePriceTestStatus() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest short_sale_price_test_status record field
    void reset() {
        data.reset();
    }

    // append short_sale_price_test_status
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // short_sale_price_test_status arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}