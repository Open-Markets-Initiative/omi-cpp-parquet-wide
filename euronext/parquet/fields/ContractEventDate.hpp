#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Contract Event Date
struct ContractEventDate {

    static constexpr auto name = "contract_event_date";
    static constexpr auto nullable = true;

    ContractEventDate() = default;

    void set(std::uint16_t value) {
        data = value;
    }

    // rest contract_event_date record field
    void reset() {
        data.reset();
    }

    // append contract_event_date
    auto append(arrow::UInt16Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // contract_event_date arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint16(), nullable);
    }

    std::optional<std::uint16_t> data;
};

}