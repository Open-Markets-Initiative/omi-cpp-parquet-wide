#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Pctg Of Capitalization
struct PctgOfCapitalization {

    static constexpr auto name = "pctg_of_capitalization";
    static constexpr auto nullable = true;

    PctgOfCapitalization() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest pctg_of_capitalization record field
    void reset() {
        data.reset();
    }

    // append pctg_of_capitalization
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // pctg_of_capitalization arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}