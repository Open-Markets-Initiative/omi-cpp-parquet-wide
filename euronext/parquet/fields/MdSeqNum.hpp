#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Md Seq Num
struct MdSeqNum {

    static constexpr auto name = "md_seq_num";
    static constexpr auto nullable = true;

    MdSeqNum() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest md_seq_num record field
    void reset() {
        data.reset();
    }

    // append md_seq_num
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_seq_num arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}