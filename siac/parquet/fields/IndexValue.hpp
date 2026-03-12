#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Index Value
struct IndexValue {

    static constexpr auto name = "index_value";
    static constexpr auto nullable = true;

    IndexValue() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest index_value record field
    void reset() {
        data.reset();
    }

    // append index_value
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // index_value arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}