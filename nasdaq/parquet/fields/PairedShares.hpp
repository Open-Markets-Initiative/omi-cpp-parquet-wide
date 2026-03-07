#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Paired Shares
struct PairedShares {

    static constexpr auto name = "paired_shares";
    static constexpr auto nullable = true;

    PairedShares() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest paired_shares record field
    void reset() {
        data.reset();
    }

    // append paired_shares
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // paired_shares arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}