#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Nanoseconds
struct Nanoseconds {

    static constexpr auto name = "nanoseconds";
    static constexpr auto nullable = true;

    Nanoseconds() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest nanoseconds record field
    void reset() {
        data.reset();
    }

    // append nanoseconds
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // nanoseconds arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}