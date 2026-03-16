#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Dividend Payment Date
struct DividendPaymentDate {

    static constexpr auto name = "dividend_payment_date";
    static constexpr auto nullable = true;

    DividendPaymentDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest dividend_payment_date record field
    void reset() {
        data.reset();
    }

    // append dividend_payment_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // dividend_payment_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}