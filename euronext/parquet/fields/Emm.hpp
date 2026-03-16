#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Emm
struct Emm {

    static constexpr auto name = "emm";
    static constexpr auto nullable = true;

    Emm() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest emm record field
    void reset() {
        data.reset();
    }

    // append emm
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // emm arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}