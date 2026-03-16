#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Dividend Rate
struct DividendRate {

    static constexpr auto name = "dividend_rate";
    static constexpr auto nullable = true;

    DividendRate() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest dividend_rate record field
    void reset() {
        data.reset();
    }

    // append dividend_rate
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // dividend_rate arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}