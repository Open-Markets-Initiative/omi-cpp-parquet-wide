#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Payment Frequency
struct PaymentFrequency {

    static constexpr auto name = "payment_frequency";
    static constexpr auto nullable = true;

    PaymentFrequency() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest payment_frequency record field
    void reset() {
        data.reset();
    }

    // append payment_frequency
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // payment_frequency arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}