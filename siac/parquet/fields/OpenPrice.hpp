#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Open Price
struct OpenPrice {

    static constexpr auto name = "open_price";
    static constexpr auto nullable = true;

    OpenPrice() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest open_price record field
    void reset() {
        data.reset();
    }

    // append open_price
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // open_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}