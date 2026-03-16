#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// field: Low Time
struct LowTime {

    static constexpr auto name = "low_time";
    static constexpr auto nullable = true;
    static constexpr auto type = arrow::TimeUnit::MICRO;
    static constexpr auto timezone = "0";

    LowTime() = default;

    void reset() {
        data.reset();
    }

    void set(const std::uint64_t value) {
        data = static_cast<std::int64_t>(value);
    }

    // append low_time
    auto append(arrow::Time64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // low_time schema field
    static auto column() {
        return arrow::field(name, arrow::timestamp(arrow::TimeUnit::NANO, timezone), nullable);
    }

    std::optional<std::int64_t> data;
};

}