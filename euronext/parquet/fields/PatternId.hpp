#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Pattern Id
struct PatternId {

    static constexpr auto name = "pattern_id";
    static constexpr auto nullable = true;

    PatternId() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest pattern_id record field
    void reset() {
        data.reset();
    }

    // append pattern_id
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // pattern_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}