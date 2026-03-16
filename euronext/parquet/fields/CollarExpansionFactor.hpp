#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Collar Expansion Factor
struct CollarExpansionFactor {

    static constexpr auto name = "collar_expansion_factor";
    static constexpr auto nullable = true;

    CollarExpansionFactor() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest collar_expansion_factor record field
    void reset() {
        data.reset();
    }

    // append collar_expansion_factor
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // collar_expansion_factor arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}