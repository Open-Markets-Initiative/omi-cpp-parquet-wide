#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Bid Index Value
struct BidIndexValue {

    static constexpr auto name = "bid_index_value";
    static constexpr auto nullable = true;

    BidIndexValue() = default;

    void set(std::int32_t value) {
        data = value;
    }

    // rest bid_index_value record field
    void reset() {
        data.reset();
    }

    // append bid_index_value
    auto append(arrow::Int32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // bid_index_value arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int32(), nullable);
    }

    std::optional<std::int32_t> data;
};

}