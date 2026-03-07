#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// field: Md Entry Px Optional
struct MdEntryPxOptional {

    static constexpr auto name = "md_entry_px_optional";
    static constexpr auto nullable = true;
    static constexpr auto precision = 18;
    static constexpr auto scale = 7;
    static constexpr auto scalar = 10000000;

    MdEntryPxOptional() = default;

    // md_entry_px_optional schema field
    void reset() {
        data.reset();
    }

    void set(const double value) {
        data = value * scalar;
    }

    [[nodiscard]] std::optional<double> display() const {
        std::optional<double> result;
        if (data) {
            result = static_cast<double>(data.value()) / scalar;
        }

        return result;
    }

    // append md_entry_px_optional
    auto append(arrow::Decimal128Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_entry_px_optional schema field
    static auto column() {
        return arrow::field(name, arrow::decimal128(precision, scale), nullable);
    }

    std::optional<std::int64_t> data;
};

}