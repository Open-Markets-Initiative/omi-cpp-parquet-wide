#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Trading Policy
struct TradingPolicy {

    static constexpr auto name = "trading_policy";
    static constexpr auto nullable = true;

    TradingPolicy() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest trading_policy record field
    void reset() {
        data.reset();
    }

    // append trading_policy
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // trading_policy arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}