#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Currency Coefficient
struct CurrencyCoefficient {

    static constexpr auto name = "currency_coefficient";
    static constexpr auto nullable = true;

    CurrencyCoefficient() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest currency_coefficient record field
    void reset() {
        data.reset();
    }

    // append currency_coefficient
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // currency_coefficient arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}