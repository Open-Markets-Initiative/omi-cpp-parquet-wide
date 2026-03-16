#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Date Of Last Trade
struct DateOfLastTrade {

    static constexpr auto name = "date_of_last_trade";
    static constexpr auto nullable = true;

    DateOfLastTrade() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest date_of_last_trade record field
    void reset() {
        data.reset();
    }

    // append date_of_last_trade
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // date_of_last_trade arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}