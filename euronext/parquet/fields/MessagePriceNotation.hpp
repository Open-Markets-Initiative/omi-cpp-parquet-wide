#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Message Price Notation
struct MessagePriceNotation {

    static constexpr auto name = "message_price_notation";
    static constexpr auto nullable = true;

    MessagePriceNotation() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest message_price_notation record field
    void reset() {
        data.reset();
    }

    // append message_price_notation
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // message_price_notation arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}