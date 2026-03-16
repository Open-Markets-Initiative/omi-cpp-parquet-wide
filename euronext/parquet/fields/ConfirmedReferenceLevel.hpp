#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Confirmed Reference Level
struct ConfirmedReferenceLevel {

    static constexpr auto name = "confirmed_reference_level";
    static constexpr auto nullable = true;

    ConfirmedReferenceLevel() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest confirmed_reference_level record field
    void reset() {
        data.reset();
    }

    // append confirmed_reference_level
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // confirmed_reference_level arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}