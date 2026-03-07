#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Display Qty
struct MdDisplayQty {

    static constexpr auto name = "md_display_qty";
    static constexpr auto nullable = true;

    MdDisplayQty() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest md_display_qty record field
    void reset() {
        data.reset();
    }

    // append md_display_qty
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_display_qty arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}