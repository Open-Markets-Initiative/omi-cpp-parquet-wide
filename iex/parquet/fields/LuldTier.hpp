#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Luld Tier
struct LuldTier {

    static constexpr auto name = "luld_tier";
    static constexpr auto nullable = true;

    LuldTier() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest luld_tier record field
    void reset() {
        data.reset();
    }

    // append luld_tier
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // luld_tier arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}