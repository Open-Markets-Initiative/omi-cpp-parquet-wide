#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Seconds
struct Seconds {

    static constexpr auto name = "seconds";
    static constexpr auto nullable = true;

    Seconds() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest seconds record field
    void reset() {
        data.reset();
    }

    // append seconds
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // seconds arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}