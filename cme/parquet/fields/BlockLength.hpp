#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Block Length
struct BlockLength {

    static constexpr auto name = "block_length";
    static constexpr auto nullable = true;

    BlockLength() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest block_length record field
    void reset() {
        data.reset();
    }

    // append block_length
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // block_length arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}