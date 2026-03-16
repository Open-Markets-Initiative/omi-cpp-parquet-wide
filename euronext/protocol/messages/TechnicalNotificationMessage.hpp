#pragma once

#include "../types/MdSeqNumOptional.hpp"
#include "../types/TechnicalNotificationType.hpp"
#include "../types/RebroadcastIndicator.hpp"
#include "../types/RetransmissionStartTime.hpp"
#include "../types/RetransmissionEndTime.hpp"
#include "../types/SymbolIndexOptional.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// TechnicalNotificationMessage
struct TechnicalNotificationMessage {

    MdSeqNumOptional md_seq_num_optional;
    TechnicalNotificationType technical_notification_type;
    RebroadcastIndicator rebroadcast_indicator;
    RetransmissionStartTime retransmission_start_time;
    RetransmissionEndTime retransmission_end_time;
    SymbolIndexOptional symbol_index_optional;

    // parse method
    static TechnicalNotificationMessage* parse(std::byte* buffer) {
        return reinterpret_cast<TechnicalNotificationMessage*>(buffer);
    }

    // parse method const
    static const TechnicalNotificationMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const TechnicalNotificationMessage*>(buffer);
    }
};

#pragma pack(pop)
}
