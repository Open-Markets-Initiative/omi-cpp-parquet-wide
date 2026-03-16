#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Lot Size Optional
struct LotSizeOptional {

    static constexpr auto name = "lot_size_optional";
    static constexpr auto nullable = true;

    LotSizeOptional() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest lot_size_optional record field
    void reset() {
        data.reset();
    }

    // append lot_size_optional
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // lot_size_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}