#pragma once

#include "../types/LastMdSeqNum.hpp"
#include "../types/SnapshotTime.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// StartOfSnapshotMessage
struct StartOfSnapshotMessage {

    LastMdSeqNum last_md_seq_num;
    SnapshotTime snapshot_time;

    // parse method
    static StartOfSnapshotMessage* parse(std::byte* buffer) {
        return reinterpret_cast<StartOfSnapshotMessage*>(buffer);
    }

    // parse method const
    static const StartOfSnapshotMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const StartOfSnapshotMessage*>(buffer);
    }
};

#pragma pack(pop)
}
