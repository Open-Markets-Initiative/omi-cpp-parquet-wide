#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Stream Offset
struct StreamOffset {

    static constexpr auto name = "stream_offset";
    static constexpr auto nullable = true;

    StreamOffset() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest stream_offset record field
    void reset() {
        data.reset();
    }

    // append stream_offset
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // stream_offset arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}