#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Participant Reference Number
struct ParticipantReferenceNumber {

    static constexpr auto name = "participant_reference_number";
    static constexpr auto nullable = true;

    ParticipantReferenceNumber() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest participant_reference_number record field
    void reset() {
        data.reset();
    }

    // append participant_reference_number
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // participant_reference_number arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}