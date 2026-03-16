#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Issue Price
struct IssuePrice {

    static constexpr auto name = "issue_price";
    static constexpr auto nullable = true;

    IssuePrice() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest issue_price record field
    void reset() {
        data.reset();
    }

    // append issue_price
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // issue_price arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}