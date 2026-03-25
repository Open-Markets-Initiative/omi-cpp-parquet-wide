#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Channel Id
struct ChannelId {

    static constexpr auto name = "channel_id";
    static constexpr auto nullable = true;

    ChannelId() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest channel_id record field
    void reset() {
        data.reset();
    }

    // append channel_id
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // channel_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}