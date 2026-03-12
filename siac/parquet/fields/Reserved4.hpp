#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Reserved 4
struct Reserved4 {

    static constexpr auto name = "reserved_4";
    static constexpr auto nullable = true;

    Reserved4() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest reserved_4 record field
    void reset() {
        data.reset();
    }

    // append reserved_4
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // reserved_4 arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}