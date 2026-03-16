#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace euronext {

// Md Seq Num Optional
struct MdSeqNumOptional {

    static constexpr auto name = "md_seq_num_optional";
    static constexpr auto nullable = true;

    MdSeqNumOptional() = default;

    void set(std::uint64_t value) {
        data = value;
    }

    // rest md_seq_num_optional record field
    void reset() {
        data.reset();
    }

    // append md_seq_num_optional
    auto append(arrow::UInt64Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // md_seq_num_optional arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint64(), nullable);
    }

    std::optional<std::uint64_t> data;
};

}