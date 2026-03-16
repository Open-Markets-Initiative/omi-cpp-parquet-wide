#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Issue Date
struct IssueDate {

    static constexpr auto name = "issue_date";
    static constexpr auto nullable = true;

    IssueDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest issue_date record field
    void reset() {
        data.reset();
    }

    // append issue_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // issue_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}