#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Optiq Segment
struct OptiqSegment {

    static constexpr auto name = "optiq_segment";
    static constexpr auto nullable = true;

    OptiqSegment() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest optiq_segment record field
    void reset() {
        data.reset();
    }

    // append optiq_segment
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // optiq_segment arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}