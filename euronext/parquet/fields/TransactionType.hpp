#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Transaction Type
struct TransactionType {

    static constexpr auto name = "transaction_type";
    static constexpr auto nullable = true;

    TransactionType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest transaction_type record field
    void reset() {
        data.reset();
    }

    // append transaction_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // transaction_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}