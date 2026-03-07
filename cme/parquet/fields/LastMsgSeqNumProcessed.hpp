#pragma once

#include <optional>
#include <cstdint>

#include "arrow/api.h"

namespace cme {

// Last Msg Seq Num Processed
struct LastMsgSeqNumProcessed {

    static constexpr auto name = "last_msg_seq_num_processed";
    static constexpr auto nullable = true;

    LastMsgSeqNumProcessed() = default;

    void set(std::uint32_t value) {
        data = value;
    }

    // rest last_msg_seq_num_processed record field
    void reset() {
        data.reset();
    }

    // append last_msg_seq_num_processed
    auto append(arrow::UInt32Builder& builder) const {
        if (data) {
            return builder.Append(*data);
        }

        return builder.AppendNull();
    }

    // last_msg_seq_num_processed arrow schema field
    static auto column() {
        return arrow::field(name, arrow::uint32(), nullable);
    }

    std::optional<std::uint32_t> data;
};

}