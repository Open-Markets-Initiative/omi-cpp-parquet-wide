#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// MarketStatusChangeMessage
struct MarketStatusChangeMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;

    // parse method
    static MarketStatusChangeMessage* parse(std::byte* buffer) {
        return reinterpret_cast<MarketStatusChangeMessage*>(buffer);
    }

    // parse method const
    static const MarketStatusChangeMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const MarketStatusChangeMessage*>(buffer);
    }
};

#pragma pack(pop)
}
