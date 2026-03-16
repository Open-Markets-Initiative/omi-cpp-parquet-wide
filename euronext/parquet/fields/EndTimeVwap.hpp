#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// End Time Vwap
struct EndTimeVwap {

    static constexpr auto name = "end_time_vwap";
    static constexpr auto nullable = true;

    EndTimeVwap() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest end_time_vwap record field
    void reset() {
        data.reset();
    }

    // append end_time_vwap
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // end_time_vwap arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}