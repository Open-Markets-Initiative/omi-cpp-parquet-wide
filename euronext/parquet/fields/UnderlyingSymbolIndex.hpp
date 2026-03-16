#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Underlying Symbol Index
struct UnderlyingSymbolIndex {

    static constexpr auto name = "underlying_symbol_index";
    static constexpr auto nullable = true;

    UnderlyingSymbolIndex() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest underlying_symbol_index record field
    void reset() {
        data.reset();
    }

    // append underlying_symbol_index
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_symbol_index arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}