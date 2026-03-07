#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Entry Size Optional
struct MdEntrySizeOptional {

    static constexpr auto name = "md_entry_size_optional";
    static constexpr auto nullable = true;

    MdEntrySizeOptional() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest md_entry_size_optional record field
    void reset() {
        data.reset();
    }

    // append md_entry_size_optional
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_entry_size_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}