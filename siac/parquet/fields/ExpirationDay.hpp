#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Expiration Day
struct ExpirationDay {

    static constexpr auto name = "expiration_day";
    static constexpr auto nullable = true;

    ExpirationDay() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest expiration_day record field
    void reset() {
        data.reset();
    }

    // append expiration_day
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // expiration_day arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}