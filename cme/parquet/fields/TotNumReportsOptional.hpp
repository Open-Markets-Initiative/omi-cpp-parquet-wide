#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Tot Num Reports Optional
struct TotNumReportsOptional {

    static constexpr auto name = "tot_num_reports_optional";
    static constexpr auto nullable = true;

    TotNumReportsOptional() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest tot_num_reports_optional record field
    void reset() {
        data.reset();
    }

    // append tot_num_reports_optional
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // tot_num_reports_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}