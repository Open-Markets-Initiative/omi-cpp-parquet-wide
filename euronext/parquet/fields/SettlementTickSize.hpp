#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Settlement Tick Size
struct SettlementTickSize {

    static constexpr auto name = "settlement_tick_size";
    static constexpr auto nullable = true;

    SettlementTickSize() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest settlement_tick_size record field
    void reset() {
        data.reset();
    }

    // append settlement_tick_size
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // settlement_tick_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}