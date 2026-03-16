#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Low Level
struct LowLevel {

    static constexpr auto name = "low_level";
    static constexpr auto nullable = true;

    LowLevel() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest low_level record field
    void reset() {
        data.reset();
    }

    // append low_level
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // low_level arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}