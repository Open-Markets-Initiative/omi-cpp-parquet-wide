#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Date Of Initial Listing
struct DateOfInitialListing {

    static constexpr auto name = "date_of_initial_listing";
    static constexpr auto nullable = true;

    DateOfInitialListing() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest date_of_initial_listing record field
    void reset() {
        data.reset();
    }

    // append date_of_initial_listing
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // date_of_initial_listing arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}