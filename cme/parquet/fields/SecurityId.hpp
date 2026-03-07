#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Security Id
struct SecurityId {

    static constexpr auto name = "security_id";
    static constexpr auto nullable = true;

    SecurityId() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest security_id record field
    void reset() {
        data.reset();
    }

    // append security_id
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // security_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}