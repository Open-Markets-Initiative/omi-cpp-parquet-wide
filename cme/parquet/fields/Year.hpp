#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Year
struct Year {

    static constexpr auto name = "year";
    static constexpr auto nullable = true;

    Year() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest year record field
    void reset() {
        data.reset();
    }

    // append year
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // year arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}