#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Open Interest Volume
struct OpenInterestVolume {

    static constexpr auto name = "open_interest_volume";
    static constexpr auto nullable = true;

    OpenInterestVolume() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest open_interest_volume record field
    void reset() {
        data.reset();
    }

    // append open_interest_volume
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // open_interest_volume arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}