#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Size
struct Size {

    static constexpr auto name = "size";
    static constexpr auto nullable = true;

    Size() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest size record field
    void reset() {
        data.reset();
    }

    // append size
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}