#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Underlying Security Id
struct UnderlyingSecurityId {

    static constexpr auto name = "underlying_security_id";
    static constexpr auto nullable = true;

    UnderlyingSecurityId() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest underlying_security_id record field
    void reset() {
        data.reset();
    }

    // append underlying_security_id
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // underlying_security_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}