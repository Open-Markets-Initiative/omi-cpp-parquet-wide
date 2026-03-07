#pragma once

#include "../bitfields/QuoteUpdateFlags.hpp"
#include "../types/Timestamp.hpp"
#include "../types/Symbol.hpp"
#include "../types/BidSize.hpp"
#include "../types/BidPrice.hpp"
#include "../types/AskPrice.hpp"
#include "../types/AskSize.hpp"

namespace iex::equities::tops::iextp::v1_6_6 {

#pragma pack(push, 1)

// Tops broadcasts a real-time Quote Update Message each time IEX's best bid or offer quotation is updated during the trading day
struct QuoteUpdateMessage {

    QuoteUpdateFlags quote_update_flags;
    Timestamp timestamp;
    Symbol symbol;
    BidSize bid_size;
    BidPrice bid_price;
    AskPrice ask_price;
    AskSize ask_size;

    // parse method
    static QuoteUpdateMessage* parse(std::byte* buffer) {
        return reinterpret_cast<QuoteUpdateMessage*>(buffer);
    }

    // parse method const
    static const QuoteUpdateMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const QuoteUpdateMessage*>(buffer);
    }
};

#pragma pack(pop)
}
