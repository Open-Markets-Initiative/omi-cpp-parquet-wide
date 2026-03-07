#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Related Security Id
struct RelatedSecurityId {

    static constexpr auto name = "related_security_id";
    static constexpr auto nullable = true;

    RelatedSecurityId() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest related_security_id record field
    void reset() {
        data.reset();
    }

    // append related_security_id
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // related_security_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}