#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Par Value
struct ParValue {

    static constexpr auto name = "par_value";
    static constexpr auto nullable = true;

    ParValue() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest par_value record field
    void reset() {
        data.reset();
    }

    // append par_value
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // par_value arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}