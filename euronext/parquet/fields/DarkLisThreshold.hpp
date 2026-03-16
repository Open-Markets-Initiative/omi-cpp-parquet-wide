#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Dark Lis Threshold
struct DarkLisThreshold {

    static constexpr auto name = "dark_lis_threshold";
    static constexpr auto nullable = true;

    DarkLisThreshold() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest dark_lis_threshold record field
    void reset() {
        data.reset();
    }

    // append dark_lis_threshold
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // dark_lis_threshold arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}