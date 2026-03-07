#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Open Interest Qty
struct OpenInterestQty {

    static constexpr auto name = "open_interest_qty";
    static constexpr auto nullable = true;

    OpenInterestQty() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest open_interest_qty record field
    void reset() {
        data.reset();
    }

    // append open_interest_qty
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // open_interest_qty arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}