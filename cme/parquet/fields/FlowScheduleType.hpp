#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Flow Schedule Type
struct FlowScheduleType {

    static constexpr auto name = "flow_schedule_type";
    static constexpr auto nullable = true;

    FlowScheduleType() = default;

    void set(std::int8_t value) {
        data = value;
    }

    // rest flow_schedule_type record field
    void reset() {
        data.reset();
    }

    // append flow_schedule_type
    auto append(arrow::Int8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // flow_schedule_type arrow schema field
    static auto column() {
        return arrow::field(name, arrow::int8(), nullable);
    }

    std::optional<std::int8_t> data;
};

}