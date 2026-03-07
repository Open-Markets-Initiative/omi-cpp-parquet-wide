#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Near Execution Time
struct NearExecutionTime {

    static constexpr auto name = "near_execution_time";
    static constexpr auto nullable = true;

    NearExecutionTime() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest near_execution_time record field
    void reset() {
        data.reset();
    }

    // append near_execution_time
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // near_execution_time arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}