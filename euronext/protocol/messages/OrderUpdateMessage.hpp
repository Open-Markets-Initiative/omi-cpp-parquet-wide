#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/Emm.hpp"
#include "../types/EventTime.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// OrderUpdateMessage
struct OrderUpdateMessage {

    MdSeqNum md_seq_num;
    RebroadcastIndicator rebroadcast_indicator;
    Emm emm;
    EventTime event_time;

    // parse method
    static OrderUpdateMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OrderUpdateMessage*>(buffer);
    }

    // parse method const
    static const OrderUpdateMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OrderUpdateMessage*>(buffer);
    }
};

#pragma pack(pop)
}
