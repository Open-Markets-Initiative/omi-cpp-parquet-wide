#pragma once

#include "../types/MdSeqNum.hpp"
#include "../types/SessionTradingDay.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

// EndOfDayMessage
struct EndOfDayMessage {

    MdSeqNum md_seq_num;
    SessionTradingDay session_trading_day;

    // parse method
    static EndOfDayMessage* parse(std::byte* buffer) {
        return reinterpret_cast<EndOfDayMessage*>(buffer);
    }

    // parse method const
    static const EndOfDayMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const EndOfDayMessage*>(buffer);
    }
};

#pragma pack(pop)
}
