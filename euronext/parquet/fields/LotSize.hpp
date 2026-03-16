#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Lot Size
struct LotSize {

    static constexpr auto name = "lot_size";
    static constexpr auto nullable = true;

    LotSize() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest lot_size record field
    void reset() {
        data.reset();
    }

    // append lot_size
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // lot_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}