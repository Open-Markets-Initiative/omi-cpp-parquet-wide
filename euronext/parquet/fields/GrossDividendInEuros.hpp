#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Gross Dividend In Euros
struct GrossDividendInEuros {

    static constexpr auto name = "gross_dividend_in_euros";
    static constexpr auto nullable = true;

    GrossDividendInEuros() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest gross_dividend_in_euros record field
    void reset() {
        data.reset();
    }

    // append gross_dividend_in_euros
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // gross_dividend_in_euros arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}