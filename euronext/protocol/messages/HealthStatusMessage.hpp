#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/EventTime.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// HealthStatusMessage
struct HealthStatusMessage {

    MdSeqNum md_seq_num;
    EventTime event_time;

    // parse method
    static HealthStatusMessage* parse(std::byte* buffer) {
        return reinterpret_cast<HealthStatusMessage*>(buffer);
    }

    // parse method const
    static const HealthStatusMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const HealthStatusMessage*>(buffer);
    }
};

#pragma pack(pop)
}
