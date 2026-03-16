#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Underlying Expiry
struct UnderlyingExpiry {

    static constexpr auto name = "underlying_expiry";
    static constexpr auto nullable = true;

    UnderlyingExpiry() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest underlying_expiry record field
    void reset() {
        data.reset();
    }

    // append underlying_expiry
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_expiry arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}