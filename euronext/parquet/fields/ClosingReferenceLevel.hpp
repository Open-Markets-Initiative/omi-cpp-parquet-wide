#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Closing Reference Level
struct ClosingReferenceLevel {

    static constexpr auto name = "closing_reference_level";
    static constexpr auto nullable = true;

    ClosingReferenceLevel() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest closing_reference_level record field
    void reset() {
        data.reset();
    }

    // append closing_reference_level
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // closing_reference_level arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}