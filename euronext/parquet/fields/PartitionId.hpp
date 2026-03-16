#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Partition Id
struct PartitionId {

    static constexpr auto name = "partition_id";
    static constexpr auto nullable = true;

    PartitionId() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest partition_id record field
    void reset() {
        data.reset();
    }

    // append partition_id
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // partition_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}