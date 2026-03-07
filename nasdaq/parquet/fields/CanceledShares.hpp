#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Canceled Shares
struct CanceledShares {

    static constexpr auto name = "canceled_shares";
    static constexpr auto nullable = true;

    CanceledShares() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest canceled_shares record field
    void reset() {
        data.reset();
    }

    // append canceled_shares
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // canceled_shares arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}