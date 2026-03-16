#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Coupon
struct Coupon {

    static constexpr auto name = "coupon";
    static constexpr auto nullable = true;

    Coupon() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest coupon record field
    void reset() {
        data.reset();
    }

    // append coupon
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // coupon arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}