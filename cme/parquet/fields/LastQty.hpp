#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Last Qty
struct LastQty {

    static constexpr auto name = "last_qty";
    static constexpr auto nullable = true;

    LastQty() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest last_qty record field
    void reset() {
        data.reset();
    }

    // append last_qty
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // last_qty arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}