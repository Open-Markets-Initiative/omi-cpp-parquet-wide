#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Efficient Mmt Market Mechanism
struct EfficientMmtMarketMechanism {

    static constexpr auto name = "efficient_mmt_market_mechanism";
    static constexpr auto nullable = true;

    EfficientMmtMarketMechanism() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest efficient_mmt_market_mechanism record field
    void reset() {
        data.reset();
    }

    // append efficient_mmt_market_mechanism
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // efficient_mmt_market_mechanism arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}