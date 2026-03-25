#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Block Checksum
struct BlockChecksum {

    static constexpr auto name = "block_checksum";
    static constexpr auto nullable = true;

    BlockChecksum() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest block_checksum record field
    void reset() {
        data.reset();
    }

    // append block_checksum
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // block_checksum arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}