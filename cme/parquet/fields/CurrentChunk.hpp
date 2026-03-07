#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Current Chunk
struct CurrentChunk {

    static constexpr auto name = "current_chunk";
    static constexpr auto nullable = true;

    CurrentChunk() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest current_chunk record field
    void reset() {
        data.reset();
    }

    // append current_chunk
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // current_chunk arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}