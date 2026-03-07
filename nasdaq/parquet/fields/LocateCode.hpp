#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Locate Code
struct LocateCode {

    static constexpr auto name = "locate_code";
    static constexpr auto nullable = true;

    LocateCode() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest locate_code record field
    void reset() {
        data.reset();
    }

    // append locate_code
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // locate_code arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}