#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Symbol Index Optional
struct SymbolIndexOptional {

    static constexpr auto name = "symbol_index_optional";
    static constexpr auto nullable = true;

    SymbolIndexOptional() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest symbol_index_optional record field
    void reset() {
        data.reset();
    }

    // append symbol_index_optional
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // symbol_index_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}