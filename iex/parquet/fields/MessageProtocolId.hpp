#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Message Protocol Id
struct MessageProtocolId {

    static constexpr auto name = "message_protocol_id";
    static constexpr auto nullable = true;

    MessageProtocolId() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest message_protocol_id record field
    void reset() {
        data.reset();
    }

    // append message_protocol_id
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // message_protocol_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}