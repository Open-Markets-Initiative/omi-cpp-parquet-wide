#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Price
struct Price {

    static constexpr auto name = "price";
    static constexpr auto nullable = true;

    Price() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest price record field
    void reset() {
        data.reset();
    }

    // append price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}