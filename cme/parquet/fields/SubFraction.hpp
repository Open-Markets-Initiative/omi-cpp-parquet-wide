#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Sub Fraction
struct SubFraction {

    static constexpr auto name = "sub_fraction";
    static constexpr auto nullable = true;

    SubFraction() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest sub_fraction record field
    void reset() {
        data.reset();
    }

    // append sub_fraction
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // sub_fraction arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}