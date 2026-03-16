#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Exer Style
struct ExerStyle {

    static constexpr auto name = "exer_style";
    static constexpr auto nullable = true;

    ExerStyle() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest exer_style record field
    void reset() {
        data.reset();
    }

    // append exer_style
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // exer_style arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}