#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Notional Amount Traded
struct NotionalAmountTraded {

    static constexpr auto name = "notional_amount_traded";
    static constexpr auto nullable = true;

    NotionalAmountTraded() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest notional_amount_traded record field
    void reset() {
        data.reset();
    }

    // append notional_amount_traded
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // notional_amount_traded arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}