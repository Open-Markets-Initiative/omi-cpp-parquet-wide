#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Update Action
struct MdUpdateAction {

    static constexpr auto name = "md_update_action";
    static constexpr auto nullable = true;

    MdUpdateAction() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest md_update_action record field
    void reset() {
        data.reset();
    }

    // append md_update_action
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_update_action arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}