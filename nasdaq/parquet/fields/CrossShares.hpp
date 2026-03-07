#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Cross Shares
struct CrossShares {

    static constexpr auto name = "cross_shares";
    static constexpr auto nullable = true;

    CrossShares() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest cross_shares record field
    void reset() {
        data.reset();
    }

    // append cross_shares
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // cross_shares arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}