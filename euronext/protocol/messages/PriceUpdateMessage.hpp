#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// PriceUpdateMessage
struct PriceUpdateMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;

    // parse method
    static PriceUpdateMessage* parse(std::byte* buffer) {
        return reinterpret_cast<PriceUpdateMessage*>(buffer);
    }

    // parse method const
    static const PriceUpdateMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const PriceUpdateMessage*>(buffer);
    }
};

#pragma pack(pop)
}
