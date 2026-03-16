#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Index Level Type
struct IndexLevelType {

    static constexpr auto name = "index_level_type";
    static constexpr auto nullable = true;

    IndexLevelType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest index_level_type record field
    void reset() {
        data.reset();
    }

    // append index_level_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // index_level_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}