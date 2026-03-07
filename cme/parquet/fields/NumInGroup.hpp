#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Num In Group
struct NumInGroup {

    static constexpr auto name = "num_in_group";
    static constexpr auto nullable = true;

    NumInGroup() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest num_in_group record field
    void reset() {
        data.reset();
    }

    // append num_in_group
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // num_in_group arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}