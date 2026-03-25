#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Timestamp
struct Timestamp {

    static constexpr auto name = "timestamp";
    static constexpr auto nullable = true;

    Timestamp() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest timestamp record field
    void reset() {
        data.reset();
    }

    // append timestamp
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // timestamp arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}