#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Order Priority
struct MdOrderPriority {

    static constexpr auto name = "md_order_priority";
    static constexpr auto nullable = true;

    MdOrderPriority() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest md_order_priority record field
    void reset() {
        data.reset();
    }

    // append md_order_priority
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_order_priority arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}