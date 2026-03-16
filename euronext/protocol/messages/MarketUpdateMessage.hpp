#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// MarketUpdateMessage
struct MarketUpdateMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;

    // parse method
    static MarketUpdateMessage* parse(std::byte* buffer) {
        return reinterpret_cast<MarketUpdateMessage*>(buffer);
    }

    // parse method const
    static const MarketUpdateMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const MarketUpdateMessage*>(buffer);
    }
};

#pragma pack(pop)
}
