#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Snapshot Time
struct SnapshotTime {

    static constexpr auto name = "snapshot_time";
    static constexpr auto nullable = true;

    SnapshotTime() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest snapshot_time record field
    void reset() {
        data.reset();
    }

    // append snapshot_time
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // snapshot_time arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}