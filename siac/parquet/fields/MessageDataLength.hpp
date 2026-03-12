#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace siac {

// Message Data Length
struct MessageDataLength {

    static constexpr auto name = "message_data_length";
    static constexpr auto nullable = true;

    MessageDataLength() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest message_data_length record field
    void reset() {
        data.reset();
    }

    // append message_data_length
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // message_data_length arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}