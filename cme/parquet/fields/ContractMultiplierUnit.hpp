#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Contract Multiplier Unit
struct ContractMultiplierUnit {

    static constexpr auto name = "contract_multiplier_unit";
    static constexpr auto nullable = true;

    ContractMultiplierUnit() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest contract_multiplier_unit record field
    void reset() {
        data.reset();
    }

    // append contract_multiplier_unit
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // contract_multiplier_unit arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}