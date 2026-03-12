#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Reserved 1
struct Reserved1 {

    static constexpr auto name = "reserved_1";
    static constexpr auto nullable = true;

    Reserved1() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest reserved_1 record field
    void reset() {
        data.reset();
    }

    // append reserved_1
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reserved_1 arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}