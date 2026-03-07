#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Main Fraction
struct MainFraction {

    static constexpr auto name = "main_fraction";
    static constexpr auto nullable = true;

    MainFraction() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest main_fraction record field
    void reset() {
        data.reset();
    }

    // append main_fraction
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // main_fraction arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}