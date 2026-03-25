#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Packet Sequence Number
struct PacketSequenceNumber {

    static constexpr auto name = "packet_sequence_number";
    static constexpr auto nullable = true;

    PacketSequenceNumber() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest packet_sequence_number record field
    void reset() {
        data.reset();
    }

    // append packet_sequence_number
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // packet_sequence_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}