#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Last Md Seq Num
struct LastMdSeqNum {

    static constexpr auto name = "last_md_seq_num";
    static constexpr auto nullable = true;

    LastMdSeqNum() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest last_md_seq_num record field
    void reset() {
        data.reset();
    }

    // append last_md_seq_num
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // last_md_seq_num arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}