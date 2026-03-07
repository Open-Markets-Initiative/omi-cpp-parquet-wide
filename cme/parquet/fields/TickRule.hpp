#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Tick Rule
struct TickRule {

    static constexpr auto name = "tick_rule";
    static constexpr auto nullable = true;

    TickRule() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest tick_rule record field
    void reset() {
        data.reset();
    }

    // append tick_rule
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // tick_rule arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}