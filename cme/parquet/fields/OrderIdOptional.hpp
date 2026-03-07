#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Order Id Optional
struct OrderIdOptional {

    static constexpr auto name = "order_id_optional";
    static constexpr auto nullable = true;

    OrderIdOptional() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest order_id_optional record field
    void reset() {
        data.reset();
    }

    // append order_id_optional
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // order_id_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}