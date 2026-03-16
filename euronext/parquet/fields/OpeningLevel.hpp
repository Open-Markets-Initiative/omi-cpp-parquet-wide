#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Opening Level
struct OpeningLevel {

    static constexpr auto name = "opening_level";
    static constexpr auto nullable = true;

    OpeningLevel() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest opening_level record field
    void reset() {
        data.reset();
    }

    // append opening_level
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // opening_level arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}