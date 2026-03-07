#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Halt Reason
struct HaltReason {

    static constexpr auto name = "halt_reason";
    static constexpr auto nullable = true;

    HaltReason() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest halt_reason record field
    void reset() {
        data.reset();
    }

    // append halt_reason
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // halt_reason arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}