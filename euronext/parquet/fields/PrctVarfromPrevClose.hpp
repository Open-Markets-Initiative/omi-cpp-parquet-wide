#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Prct Varfrom Prev Close
struct PrctVarfromPrevClose {

    static constexpr auto name = "prct_varfrom_prev_close";
    static constexpr auto nullable = true;

    PrctVarfromPrevClose() = default;

    void set(std::int64_t value) {
        data = value;
    }

    // rest prct_varfrom_prev_close record field
    void reset() {
        data.reset();
    }

    // append prct_varfrom_prev_close
    auto append(arrow::Int64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // prct_varfrom_prev_close arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int64(), nullable);
    }

    std::optional<std::int64_t> data;
};

}