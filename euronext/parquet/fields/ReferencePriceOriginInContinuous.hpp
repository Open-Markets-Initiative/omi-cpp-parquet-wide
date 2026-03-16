#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Reference Price Origin In Continuous
struct ReferencePriceOriginInContinuous {

    static constexpr auto name = "reference_price_origin_in_continuous";
    static constexpr auto nullable = true;

    ReferencePriceOriginInContinuous() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest reference_price_origin_in_continuous record field
    void reset() {
        data.reset();
    }

    // append reference_price_origin_in_continuous
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reference_price_origin_in_continuous arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}