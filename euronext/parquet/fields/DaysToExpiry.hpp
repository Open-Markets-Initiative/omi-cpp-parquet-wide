#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Days To Expiry
struct DaysToExpiry {

    static constexpr auto name = "days_to_expiry";
    static constexpr auto nullable = true;

    DaysToExpiry() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest days_to_expiry record field
    void reset() {
        data.reset();
    }

    // append days_to_expiry
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // days_to_expiry arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}