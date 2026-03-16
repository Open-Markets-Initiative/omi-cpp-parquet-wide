#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Share Amount In Issue
struct ShareAmountInIssue {

    static constexpr auto name = "share_amount_in_issue";
    static constexpr auto nullable = true;

    ShareAmountInIssue() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest share_amount_in_issue record field
    void reset() {
        data.reset();
    }

    // append share_amount_in_issue
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // share_amount_in_issue arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}