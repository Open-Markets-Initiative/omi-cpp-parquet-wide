#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace iex {

// Session Id
struct SessionId {

    static constexpr auto name = "session_id";
    static constexpr auto nullable = true;

    SessionId() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest session_id record field
    void reset() {
        data.reset();
    }

    // append session_id
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // session_id arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}