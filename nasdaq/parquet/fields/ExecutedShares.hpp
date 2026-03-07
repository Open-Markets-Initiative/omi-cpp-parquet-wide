#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Executed Shares
struct ExecutedShares {

    static constexpr auto name = "executed_shares";
    static constexpr auto nullable = true;

    ExecutedShares() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest executed_shares record field
    void reset() {
        data.reset();
    }

    // append executed_shares
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // executed_shares arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}