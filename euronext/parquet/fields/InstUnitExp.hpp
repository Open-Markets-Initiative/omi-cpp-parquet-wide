#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Inst Unit Exp
struct InstUnitExp {

    static constexpr auto name = "inst_unit_exp";
    static constexpr auto nullable = true;

    InstUnitExp() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest inst_unit_exp record field
    void reset() {
        data.reset();
    }

    // append inst_unit_exp
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // inst_unit_exp arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}