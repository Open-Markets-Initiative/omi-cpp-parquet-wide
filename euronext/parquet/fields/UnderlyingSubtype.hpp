#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Underlying Subtype
struct UnderlyingSubtype {

    static constexpr auto name = "underlying_subtype";
    static constexpr auto nullable = true;

    UnderlyingSubtype() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest underlying_subtype record field
    void reset() {
        data.reset();
    }

    // append underlying_subtype
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_subtype arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}