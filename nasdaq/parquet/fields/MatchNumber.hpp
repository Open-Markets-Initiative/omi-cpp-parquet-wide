#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Match Number
struct MatchNumber {

    static constexpr auto name = "match_number";
    static constexpr auto nullable = true;

    MatchNumber() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest match_number record field
    void reset() {
        data.reset();
    }

    // append match_number
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // match_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}