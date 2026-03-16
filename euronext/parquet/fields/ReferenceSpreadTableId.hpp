#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Reference Spread Table Id
struct ReferenceSpreadTableId {

    static constexpr auto name = "reference_spread_table_id";
    static constexpr auto nullable = true;

    ReferenceSpreadTableId() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest reference_spread_table_id record field
    void reset() {
        data.reset();
    }

    // append reference_spread_table_id
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reference_spread_table_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}