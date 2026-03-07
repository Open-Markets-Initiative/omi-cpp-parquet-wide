#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Original Contract Size
struct OriginalContractSize {

    static constexpr auto name = "original_contract_size";
    static constexpr auto nullable = true;

    OriginalContractSize() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest original_contract_size record field
    void reset() {
        data.reset();
    }

    // append original_contract_size
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // original_contract_size arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}