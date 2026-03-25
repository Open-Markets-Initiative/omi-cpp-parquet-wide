#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Payload Length
struct PayloadLength {

    static constexpr auto name = "payload_length";
    static constexpr auto nullable = true;

    PayloadLength() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest payload_length record field
    void reset() {
        data.reset();
    }

    // append payload_length
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // payload_length arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}