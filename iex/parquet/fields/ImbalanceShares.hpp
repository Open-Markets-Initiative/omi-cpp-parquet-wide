#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Imbalance Shares
struct ImbalanceShares {

    static constexpr auto name = "imbalance_shares";
    static constexpr auto nullable = true;

    ImbalanceShares() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest imbalance_shares record field
    void reset() {
        data.reset();
    }

    // append imbalance_shares
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // imbalance_shares arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}