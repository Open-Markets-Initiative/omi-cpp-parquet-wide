#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Contract Multiplier
struct ContractMultiplier {

    static constexpr auto name = "contract_multiplier";
    static constexpr auto nullable = true;

    ContractMultiplier() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest contract_multiplier record field
    void reset() {
        data.reset();
    }

    // append contract_multiplier
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // contract_multiplier arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}