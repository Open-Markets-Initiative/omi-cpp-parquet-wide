#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Expiry Cycle Type
struct ExpiryCycleType {

    static constexpr auto name = "expiry_cycle_type";
    static constexpr auto nullable = true;

    ExpiryCycleType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest expiry_cycle_type record field
    void reset() {
        data.reset();
    }

    // append expiry_cycle_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // expiry_cycle_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}