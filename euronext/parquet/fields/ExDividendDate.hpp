#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Ex Dividend Date
struct ExDividendDate {

    static constexpr auto name = "ex_dividend_date";
    static constexpr auto nullable = true;

    ExDividendDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest ex_dividend_date record field
    void reset() {
        data.reset();
    }

    // append ex_dividend_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ex_dividend_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}