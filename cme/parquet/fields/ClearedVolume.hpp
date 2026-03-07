#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Cleared Volume
struct ClearedVolume {

    static constexpr auto name = "cleared_volume";
    static constexpr auto nullable = true;

    ClearedVolume() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest cleared_volume record field
    void reset() {
        data.reset();
    }

    // append cleared_volume
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // cleared_volume arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}