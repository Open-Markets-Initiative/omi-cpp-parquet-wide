#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Edsp Tick Size
struct EdspTickSize {

    static constexpr auto name = "edsp_tick_size";
    static constexpr auto nullable = true;

    EdspTickSize() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest edsp_tick_size record field
    void reset() {
        data.reset();
    }

    // append edsp_tick_size
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // edsp_tick_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}