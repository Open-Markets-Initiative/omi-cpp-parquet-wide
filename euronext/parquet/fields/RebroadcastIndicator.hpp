#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Rebroadcast Indicator
struct RebroadcastIndicator {

    static constexpr auto name = "rebroadcast_indicator";
    static constexpr auto nullable = true;

    RebroadcastIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest rebroadcast_indicator record field
    void reset() {
        data.reset();
    }

    // append rebroadcast_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // rebroadcast_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}