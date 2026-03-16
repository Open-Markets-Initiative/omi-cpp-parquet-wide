#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Derivatives Market Model
struct DerivativesMarketModel {

    static constexpr auto name = "derivatives_market_model";
    static constexpr auto nullable = true;

    DerivativesMarketModel() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest derivatives_market_model record field
    void reset() {
        data.reset();
    }

    // append derivatives_market_model
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // derivatives_market_model arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}