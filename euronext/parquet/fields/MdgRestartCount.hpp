#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Mdg Restart Count
struct MdgRestartCount {

    static constexpr auto name = "mdg_restart_count";
    static constexpr auto nullable = true;

    MdgRestartCount() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest mdg_restart_count record field
    void reset() {
        data.reset();
    }

    // append mdg_restart_count
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // mdg_restart_count arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}