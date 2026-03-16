#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Quote Update Type
struct QuoteUpdateType {

    static constexpr auto name = "quote_update_type";
    static constexpr auto nullable = true;

    QuoteUpdateType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest quote_update_type record field
    void reset() {
        data.reset();
    }

    // append quote_update_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // quote_update_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}