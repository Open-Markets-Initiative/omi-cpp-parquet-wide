#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Shares
struct Shares {

    static constexpr auto name = "shares";
    static constexpr auto nullable = true;

    Shares() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest shares record field
    void reset() {
        data.reset();
    }

    // append shares
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // shares arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}