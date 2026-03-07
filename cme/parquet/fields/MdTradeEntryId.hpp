#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Trade Entry Id
struct MdTradeEntryId {

    static constexpr auto name = "md_trade_entry_id";
    static constexpr auto nullable = true;

    MdTradeEntryId() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest md_trade_entry_id record field
    void reset() {
        data.reset();
    }

    // append md_trade_entry_id
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_trade_entry_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}