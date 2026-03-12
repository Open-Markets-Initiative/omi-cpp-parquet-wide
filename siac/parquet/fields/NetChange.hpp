#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Net Change
struct NetChange {

    static constexpr auto name = "net_change";
    static constexpr auto nullable = true;

    NetChange() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest net_change record field
    void reset() {
        data.reset();
    }

    // append net_change
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // net_change arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}