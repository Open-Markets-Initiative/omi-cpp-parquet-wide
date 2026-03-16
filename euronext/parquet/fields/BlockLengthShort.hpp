#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Block Length Short
struct BlockLengthShort {

    static constexpr auto name = "block_length_short";
    static constexpr auto nullable = true;

    BlockLengthShort() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest block_length_short record field
    void reset() {
        data.reset();
    }

    // append block_length_short
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // block_length_short arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}