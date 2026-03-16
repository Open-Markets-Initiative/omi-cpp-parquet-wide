#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/SessionTradingDay.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// StartOfDayMessage
struct StartOfDayMessage {

    MdSeqNum md_seq_num;
    SessionTradingDay session_trading_day;

    // parse method
    static StartOfDayMessage* parse(std::byte* buffer) {
        return reinterpret_cast<StartOfDayMessage*>(buffer);
    }

    // parse method const
    static const StartOfDayMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const StartOfDayMessage*>(buffer);
    }
};

#pragma pack(pop)
}
