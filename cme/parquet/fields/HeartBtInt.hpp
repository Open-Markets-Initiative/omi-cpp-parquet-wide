#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Heart Bt Int
struct HeartBtInt {

    static constexpr auto name = "heart_bt_int";
    static constexpr auto nullable = true;

    HeartBtInt() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest heart_bt_int record field
    void reset() {
        data.reset();
    }

    // append heart_bt_int
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // heart_bt_int arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}