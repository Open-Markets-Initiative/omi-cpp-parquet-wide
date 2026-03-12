#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Transaction Id
struct TransactionId {

    static constexpr auto name = "transaction_id";
    static constexpr auto nullable = true;

    TransactionId() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest transaction_id record field
    void reset() {
        data.reset();
    }

    // append transaction_id
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // transaction_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}