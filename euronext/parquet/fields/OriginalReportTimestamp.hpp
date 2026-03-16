#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// field: Original Report Timestamp
struct OriginalReportTimestamp {

    static constexpr auto name = "original_report_timestamp";
    static constexpr auto nullable = true;
    static constexpr auto type = arrow::TimeUnit::MICRO;
    static constexpr auto timezone = "0";

    OriginalReportTimestamp() = default;

    void reset() {
        data.reset();
    }

    void set(const std::uint64_t value) {
        data = static_cast<std::int64_t>(value);
    }

    // append original_report_timestamp
    auto append(arrow::Time64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // original_report_timestamp schema field
    static auto column() {
        return arrow::field(name, arrow::timestamp(arrow::TimeUnit::NANO, timezone), nullable);
    }

    std::optional<std::int64_t> data;
};

}