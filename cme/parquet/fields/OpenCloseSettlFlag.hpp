#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Open Close Settl Flag
struct OpenCloseSettlFlag {

    static constexpr auto name = "open_close_settl_flag";
    static constexpr auto nullable = true;

    OpenCloseSettlFlag() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest open_close_settl_flag record field
    void reset() {
        data.reset();
    }

    // append open_close_settl_flag
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // open_close_settl_flag arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}