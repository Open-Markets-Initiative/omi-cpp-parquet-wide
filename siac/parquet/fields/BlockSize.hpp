#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Block Size
struct BlockSize {

    static constexpr auto name = "block_size";
    static constexpr auto nullable = true;

    BlockSize() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest block_size record field
    void reset() {
        data.reset();
    }

    // append block_size
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // block_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}