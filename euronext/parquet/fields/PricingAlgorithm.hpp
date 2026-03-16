#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Pricing Algorithm
struct PricingAlgorithm {

    static constexpr auto name = "pricing_algorithm";
    static constexpr auto nullable = true;

    PricingAlgorithm() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest pricing_algorithm record field
    void reset() {
        data.reset();
    }

    // append pricing_algorithm
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // pricing_algorithm arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}