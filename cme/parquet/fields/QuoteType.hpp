#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Quote Type
struct QuoteType {

    static constexpr auto name = "quote_type";
    static constexpr auto nullable = true;

    QuoteType() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest quote_type record field
    void reset() {
        data.reset();
    }

    // append quote_type
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // quote_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}