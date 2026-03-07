#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Tot Num Reports
struct TotNumReports {

    static constexpr auto name = "tot_num_reports";
    static constexpr auto nullable = true;

    TotNumReports() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest tot_num_reports record field
    void reset() {
        data.reset();
    }

    // append tot_num_reports
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // tot_num_reports arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}