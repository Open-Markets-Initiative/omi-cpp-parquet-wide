#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Settlement Date
struct SettlementDate {

    static constexpr auto name = "settlement_date";
    static constexpr auto nullable = true;

    SettlementDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest settlement_date record field
    void reset() {
        data.reset();
    }

    // append settlement_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // settlement_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}