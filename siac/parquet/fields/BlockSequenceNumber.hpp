#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Block Sequence Number
struct BlockSequenceNumber {

    static constexpr auto name = "block_sequence_number";
    static constexpr auto nullable = true;

    BlockSequenceNumber() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest block_sequence_number record field
    void reset() {
        data.reset();
    }

    // append block_sequence_number
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // block_sequence_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}