#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Dark Eligibility
struct DarkEligibility {

    static constexpr auto name = "dark_eligibility";
    static constexpr auto nullable = true;

    DarkEligibility() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest dark_eligibility record field
    void reset() {
        data.reset();
    }

    // append dark_eligibility
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // dark_eligibility arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}