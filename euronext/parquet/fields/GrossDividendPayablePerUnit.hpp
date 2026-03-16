#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Gross Dividend Payable Per Unit
struct GrossDividendPayablePerUnit {

    static constexpr auto name = "gross_dividend_payable_per_unit";
    static constexpr auto nullable = true;

    GrossDividendPayablePerUnit() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest gross_dividend_payable_per_unit record field
    void reset() {
        data.reset();
    }

    // append gross_dividend_payable_per_unit
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // gross_dividend_payable_per_unit arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}