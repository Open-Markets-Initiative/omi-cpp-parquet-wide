#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Price Level Optional
struct MdPriceLevelOptional {

    static constexpr auto name = "md_price_level_optional";
    static constexpr auto nullable = true;

    MdPriceLevelOptional() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest md_price_level_optional record field
    void reset() {
        data.reset();
    }

    // append md_price_level_optional
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_price_level_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}