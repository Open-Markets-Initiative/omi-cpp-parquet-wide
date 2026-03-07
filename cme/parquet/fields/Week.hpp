#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Week
struct Week {

    static constexpr auto name = "week";
    static constexpr auto nullable = true;

    Week() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest week record field
    void reset() {
        data.reset();
    }

    // append week
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // week arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}