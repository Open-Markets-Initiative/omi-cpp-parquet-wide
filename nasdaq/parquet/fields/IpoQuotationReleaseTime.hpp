#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace nasdaq {

// Ipo Quotation Release Time
struct IpoQuotationReleaseTime {

    static constexpr auto name = "ipo_quotation_release_time";
    static constexpr auto nullable = true;

    IpoQuotationReleaseTime() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest ipo_quotation_release_time record field
    void reset() {
        data.reset();
    }

    // append ipo_quotation_release_time
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // ipo_quotation_release_time arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}