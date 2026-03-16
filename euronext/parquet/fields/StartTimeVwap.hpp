#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Start Time Vwap
struct StartTimeVwap {

    static constexpr auto name = "start_time_vwap";
    static constexpr auto nullable = true;

    StartTimeVwap() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest start_time_vwap record field
    void reset() {
        data.reset();
    }

    // append start_time_vwap
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // start_time_vwap arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}