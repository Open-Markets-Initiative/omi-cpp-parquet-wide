#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Order Reference Number
struct OrderReferenceNumber {

    static constexpr auto name = "order_reference_number";
    static constexpr auto nullable = true;

    OrderReferenceNumber() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest order_reference_number record field
    void reset() {
        data.reset();
    }

    // append order_reference_number
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // order_reference_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}