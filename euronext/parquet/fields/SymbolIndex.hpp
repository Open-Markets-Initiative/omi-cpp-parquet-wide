#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Symbol Index
struct SymbolIndex {

    static constexpr auto name = "symbol_index";
    static constexpr auto nullable = true;

    SymbolIndex() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest symbol_index record field
    void reset() {
        data.reset();
    }

    // append symbol_index
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // symbol_index arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}