#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Option Type
struct OptionType {

    static constexpr auto name = "option_type";
    static constexpr auto nullable = true;

    OptionType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest option_type record field
    void reset() {
        data.reset();
    }

    // append option_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // option_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}