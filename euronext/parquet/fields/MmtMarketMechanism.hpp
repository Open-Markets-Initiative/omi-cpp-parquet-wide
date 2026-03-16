#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Mmt Market Mechanism
struct MmtMarketMechanism {

    static constexpr auto name = "mmt_market_mechanism";
    static constexpr auto nullable = true;

    MmtMarketMechanism() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest mmt_market_mechanism record field
    void reset() {
        data.reset();
    }

    // append mmt_market_mechanism
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // mmt_market_mechanism arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}