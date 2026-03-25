#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Session Indicator
struct SessionIndicator {

    static constexpr auto name = "session_indicator";
    static constexpr auto nullable = true;

    SessionIndicator() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest session_indicator record field
    void reset() {
        data.reset();
    }

    // append session_indicator
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // session_indicator arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}