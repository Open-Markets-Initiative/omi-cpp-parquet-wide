#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Round Lot Size
struct RoundLotSize {

    static constexpr auto name = "round_lot_size";
    static constexpr auto nullable = true;

    RoundLotSize() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest round_lot_size record field
    void reset() {
        data.reset();
    }

    // append round_lot_size
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // round_lot_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}