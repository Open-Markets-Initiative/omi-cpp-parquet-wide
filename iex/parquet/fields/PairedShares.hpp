#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Paired Shares
struct PairedShares {

    static constexpr auto name = "paired_shares";
    static constexpr auto nullable = true;

    PairedShares() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest paired_shares record field
    void reset() {
        data.reset();
    }

    // append paired_shares
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // paired_shares arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}