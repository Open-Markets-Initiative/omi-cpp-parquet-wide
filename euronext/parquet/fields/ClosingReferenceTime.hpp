#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Closing Reference Time
struct ClosingReferenceTime {

    static constexpr auto name = "closing_reference_time";
    static constexpr auto nullable = true;

    ClosingReferenceTime() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest closing_reference_time record field
    void reset() {
        data.reset();
    }

    // append closing_reference_time
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // closing_reference_time arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}