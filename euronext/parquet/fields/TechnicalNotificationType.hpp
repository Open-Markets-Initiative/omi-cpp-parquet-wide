#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Technical Notification Type
struct TechnicalNotificationType {

    static constexpr auto name = "technical_notification_type";
    static constexpr auto nullable = true;

    TechnicalNotificationType() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest technical_notification_type record field
    void reset() {
        data.reset();
    }

    // append technical_notification_type
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // technical_notification_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}