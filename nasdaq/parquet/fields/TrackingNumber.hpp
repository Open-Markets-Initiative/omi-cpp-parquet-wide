#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Tracking Number
struct TrackingNumber {

    static constexpr auto name = "tracking_number";
    static constexpr auto nullable = true;

    TrackingNumber() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest tracking_number record field
    void reset() {
        data.reset();
    }

    // append tracking_number
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // tracking_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}