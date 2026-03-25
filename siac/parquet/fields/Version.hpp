#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Version
struct Version {

    static constexpr auto name = "version";
    static constexpr auto nullable = true;

    Version() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest version record field
    void reset() {
        data.reset();
    }

    // append version
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // version arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}