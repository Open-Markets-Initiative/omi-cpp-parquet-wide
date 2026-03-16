#pragma once

#include "../types/LastMdSeqNum.hpp"
#include "../types/SnapshotTime.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// EndOfSnapshotMessage
struct EndOfSnapshotMessage {

    LastMdSeqNum last_md_seq_num;
    SnapshotTime snapshot_time;

    // parse method
    static EndOfSnapshotMessage* parse(std::byte* buffer) {
        return reinterpret_cast<EndOfSnapshotMessage*>(buffer);
    }

    // parse method const
    static const EndOfSnapshotMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const EndOfSnapshotMessage*>(buffer);
    }
};

#pragma pack(pop)
}
