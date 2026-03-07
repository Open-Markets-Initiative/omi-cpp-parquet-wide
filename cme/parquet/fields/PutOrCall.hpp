#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Put Or Call
struct PutOrCall {

    static constexpr auto name = "put_or_call";
    static constexpr auto nullable = true;

    PutOrCall() = default;

    void set(std::uint8_t value) {
        data = value;
    }

    // rest put_or_call record field
    void reset() {
        data.reset();
    }

    // append put_or_call
    auto append(arrow::UInt8Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // put_or_call arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint8(), nullable);
    }

    std::optional<std::uint8_t> data;
};

}