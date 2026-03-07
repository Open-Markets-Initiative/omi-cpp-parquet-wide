#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Etp Leverage Factor
struct EtpLeverageFactor {

    static constexpr auto name = "etp_leverage_factor";
    static constexpr auto nullable = true;

    EtpLeverageFactor() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest etp_leverage_factor record field
    void reset() {
        data.reset();
    }

    // append etp_leverage_factor
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // etp_leverage_factor arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}