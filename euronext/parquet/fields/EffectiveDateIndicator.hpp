#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Effective Date Indicator
struct EffectiveDateIndicator {

    static constexpr auto name = "effective_date_indicator";
    static constexpr auto nullable = true;

    EffectiveDateIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest effective_date_indicator record field
    void reset() {
        data.reset();
    }

    // append effective_date_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // effective_date_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}