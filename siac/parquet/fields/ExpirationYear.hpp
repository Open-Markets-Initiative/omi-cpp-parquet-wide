#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Expiration Year
struct ExpirationYear {

    static constexpr auto name = "expiration_year";
    static constexpr auto nullable = true;

    ExpirationYear() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest expiration_year record field
    void reset() {
        data.reset();
    }

    // append expiration_year
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // expiration_year arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}