#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Contract Symbol Index
struct ContractSymbolIndex {

    static constexpr auto name = "contract_symbol_index";
    static constexpr auto nullable = true;

    ContractSymbolIndex() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest contract_symbol_index record field
    void reset() {
        data.reset();
    }

    // append contract_symbol_index
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // contract_symbol_index arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}