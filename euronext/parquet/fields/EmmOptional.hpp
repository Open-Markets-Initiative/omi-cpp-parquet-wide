#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Emm Optional
struct EmmOptional {

    static constexpr auto name = "emm_optional";
    static constexpr auto nullable = true;

    EmmOptional() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest emm_optional record field
    void reset() {
        data.reset();
    }

    // append emm_optional
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // emm_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}