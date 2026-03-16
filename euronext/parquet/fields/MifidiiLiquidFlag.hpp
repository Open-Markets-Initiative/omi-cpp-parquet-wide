#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Mifidii Liquid Flag
struct MifidiiLiquidFlag {

    static constexpr auto name = "mifidii_liquid_flag";
    static constexpr auto nullable = true;

    MifidiiLiquidFlag() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest mifidii_liquid_flag record field
    void reset() {
        data.reset();
    }

    // append mifidii_liquid_flag
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // mifidii_liquid_flag arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}