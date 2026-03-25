#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// First Message Sequence Number
struct FirstMessageSequenceNumber {

    static constexpr auto name = "first_message_sequence_number";
    static constexpr auto nullable = true;

    FirstMessageSequenceNumber() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest first_message_sequence_number record field
    void reset() {
        data.reset();
    }

    // append first_message_sequence_number
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // first_message_sequence_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}