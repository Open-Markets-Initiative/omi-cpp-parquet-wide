#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Rpt Seq
struct RptSeq {

    static constexpr auto name = "rpt_seq";
    static constexpr auto nullable = true;

    RptSeq() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest rpt_seq record field
    void reset() {
        data.reset();
    }

    // append rpt_seq
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // rpt_seq arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}