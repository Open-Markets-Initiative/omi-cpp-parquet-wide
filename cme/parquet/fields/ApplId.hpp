#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Appl Id
struct ApplId {

    static constexpr auto name = "appl_id";
    static constexpr auto nullable = true;

    ApplId() = default;

    void set(std::int16_t value) {
        data = value;
    }

    // rest appl_id record field
    void reset() {
        data.reset();
    }

    // append appl_id
    auto append(arrow::Int16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // appl_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int16(), nullable);
    }

    std::optional<std::int16_t> data;
};

}