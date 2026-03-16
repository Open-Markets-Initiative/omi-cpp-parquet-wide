#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// First Settlement Date
struct FirstSettlementDate {

    static constexpr auto name = "first_settlement_date";
    static constexpr auto nullable = true;

    FirstSettlementDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest first_settlement_date record field
    void reset() {
        data.reset();
    }

    // append first_settlement_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // first_settlement_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}