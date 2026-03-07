#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Stock Locate
struct StockLocate {

    static constexpr auto name = "stock_locate";
    static constexpr auto nullable = true;

    StockLocate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest stock_locate record field
    void reset() {
        data.reset();
    }

    // append stock_locate
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // stock_locate arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}