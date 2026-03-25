#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Psn High Weight
struct PsnHighWeight {

    static constexpr auto name = "psn_high_weight";
    static constexpr auto nullable = true;

    PsnHighWeight() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest psn_high_weight record field
    void reset() {
        data.reset();
    }

    // append psn_high_weight
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // psn_high_weight arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}