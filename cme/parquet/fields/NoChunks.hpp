#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// No Chunks
struct NoChunks {

    static constexpr auto name = "no_chunks";
    static constexpr auto nullable = true;

    NoChunks() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest no_chunks record field
    void reset() {
        data.reset();
    }

    // append no_chunks
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // no_chunks arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}