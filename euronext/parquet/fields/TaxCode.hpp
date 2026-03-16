#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Tax Code
struct TaxCode {

    static constexpr auto name = "tax_code";
    static constexpr auto nullable = true;

    TaxCode() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest tax_code record field
    void reset() {
        data.reset();
    }

    // append tax_code
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // tax_code arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}