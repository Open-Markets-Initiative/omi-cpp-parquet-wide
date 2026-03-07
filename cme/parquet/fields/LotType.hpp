#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Lot Type
struct LotType {

    static constexpr auto name = "lot_type";
    static constexpr auto nullable = true;

    LotType() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest lot_type record field
    void reset() {
        data.reset();
    }

    // append lot_type
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // lot_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}