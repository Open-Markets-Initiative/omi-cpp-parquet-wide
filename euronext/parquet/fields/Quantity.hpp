#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Quantity
struct Quantity {

    static constexpr auto name = "quantity";
    static constexpr auto nullable = true;

    Quantity() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest quantity record field
    void reset() {
        data.reset();
    }

    // append quantity
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // quantity arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}