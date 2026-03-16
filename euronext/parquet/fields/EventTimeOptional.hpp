#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Event Time Optional
struct EventTimeOptional {

    static constexpr auto name = "event_time_optional";
    static constexpr auto nullable = true;

    EventTimeOptional() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest event_time_optional record field
    void reset() {
        data.reset();
    }

    // append event_time_optional
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // event_time_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}