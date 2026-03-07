#pragma once

#include "../bitfields/SaleConditionFlags.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/Size.hpp"
#include "../types/Price.hpp"
#include "../types/TradeId.hpp"

namespace iex::equities::tops::iextp::v1_6_6 {

#pragma pack(push, 1)

// Trade Report Messages are sent when an order on the IEX Order Book is executed in whole or in part
struct TradeReportMessage {

    SaleConditionFlags sale_condition_flags;
    Timestamp timestamp;
    Symbol symbol;
    Size size;
    Price price;
    TradeId trade_id;

    // parse method
    static TradeReportMessage* parse(std::byte* buffer) {
        return reinterpret_cast<TradeReportMessage*>(buffer);
    }

    // parse method const
    static const TradeReportMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const TradeReportMessage*>(buffer);
    }
};

#pragma pack(pop)
}
