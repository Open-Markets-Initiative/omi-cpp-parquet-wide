#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Reference Id
struct ReferenceId {

    static constexpr auto name = "reference_id";
    static constexpr auto nullable = true;

    ReferenceId() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest reference_id record field
    void reset() {
        data.reset();
    }

    // append reference_id
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reference_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}