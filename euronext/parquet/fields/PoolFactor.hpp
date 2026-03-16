#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Pool Factor
struct PoolFactor {

    static constexpr auto name = "pool_factor";
    static constexpr auto nullable = true;

    PoolFactor() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest pool_factor record field
    void reset() {
        data.reset();
    }

    // append pool_factor
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // pool_factor arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}