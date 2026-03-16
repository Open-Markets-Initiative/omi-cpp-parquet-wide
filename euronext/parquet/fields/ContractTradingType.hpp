#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Contract Trading Type
struct ContractTradingType {

    static constexpr auto name = "contract_trading_type";
    static constexpr auto nullable = true;

    ContractTradingType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest contract_trading_type record field
    void reset() {
        data.reset();
    }

    // append contract_trading_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // contract_trading_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}