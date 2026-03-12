#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Volume
struct Volume {

    static constexpr auto name = "volume";
    static constexpr auto nullable = true;

    Volume() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest volume record field
    void reset() {
        data.reset();
    }

    // append volume
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // volume arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}