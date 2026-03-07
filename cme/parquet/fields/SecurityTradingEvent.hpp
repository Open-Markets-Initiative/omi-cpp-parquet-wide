#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Security Trading Event
struct SecurityTradingEvent {

    static constexpr auto name = "security_trading_event";
    static constexpr auto nullable = true;

    SecurityTradingEvent() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest security_trading_event record field
    void reset() {
        data.reset();
    }

    // append security_trading_event
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // security_trading_event arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}