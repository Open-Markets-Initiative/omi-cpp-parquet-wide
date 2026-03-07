#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Side
struct Side {

    static constexpr auto name = "side";
    static constexpr auto nullable = true;

    Side() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest side record field
    void reset() {
        data.reset();
    }

    // append side
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // side arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}