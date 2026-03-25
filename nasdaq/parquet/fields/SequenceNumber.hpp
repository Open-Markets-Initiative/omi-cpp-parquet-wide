#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Sequence Number
struct SequenceNumber {

    static constexpr auto name = "sequence_number";
    static constexpr auto nullable = true;

    SequenceNumber() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest sequence_number record field
    void reset() {
        data.reset();
    }

    // append sequence_number
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // sequence_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}