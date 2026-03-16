#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Minimum Amount
struct MinimumAmount {

    static constexpr auto name = "minimum_amount";
    static constexpr auto nullable = true;

    MinimumAmount() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest minimum_amount record field
    void reset() {
        data.reset();
    }

    // append minimum_amount
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // minimum_amount arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}