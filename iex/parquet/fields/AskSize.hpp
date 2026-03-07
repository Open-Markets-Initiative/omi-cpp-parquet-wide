#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Ask Size
struct AskSize {

    static constexpr auto name = "ask_size";
    static constexpr auto nullable = true;

    AskSize() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest ask_size record field
    void reset() {
        data.reset();
    }

    // append ask_size
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ask_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}