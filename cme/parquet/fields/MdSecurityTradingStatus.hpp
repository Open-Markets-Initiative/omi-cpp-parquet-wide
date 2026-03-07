#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Md Security Trading Status
struct MdSecurityTradingStatus {

    static constexpr auto name = "md_security_trading_status";
    static constexpr auto nullable = true;

    MdSecurityTradingStatus() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest md_security_trading_status record field
    void reset() {
        data.reset();
    }

    // append md_security_trading_status
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_security_trading_status arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}