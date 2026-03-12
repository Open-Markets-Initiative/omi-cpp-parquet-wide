#pragma once

#include "../types/ShortEquityAndIndexQuoteMessageType.hpp"
#include "../types/BboIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/SecuritySymbolShort.hpp"
#include "../structs/ExpirationBlock.hpp"
#include "../types/StrikePriceShort.hpp"
#include "../types/BidPriceShort.hpp"
#include "../types/BidSizeShort.hpp"
#include "../types/OfferPriceShort.hpp"
#include "../types/OfferSizeShort.hpp"
#include "../structs/BestBidAppendage.hpp"
#include "../structs/BestOfferAppendage.hpp"

namespace siac::opra::recipient::obi::v6_2 {

#pragma pack(push, 1)

struct ShortEquityAndIndexQuote {

    ShortEquityAndIndexQuoteMessageType short_equity_and_index_quote_message_type;
    BboIndicator bbo_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    SecuritySymbolShort security_symbol_short;
    ExpirationBlock expiration_block;
    StrikePriceShort strike_price_short;
    BidPriceShort bid_price_short;
    BidSizeShort bid_size_short;
    OfferPriceShort offer_price_short;
    OfferSizeShort offer_size_short;
    BestBidAppendage best_bid_appendage;
    BestOfferAppendage best_offer_appendage;

    // parse method
    static ShortEquityAndIndexQuote* parse(std::byte* buffer) {
        return reinterpret_cast<ShortEquityAndIndexQuote*>(buffer);
    }

    // parse method const
    static const ShortEquityAndIndexQuote* parse(const std::byte* buffer) {
        return reinterpret_cast<const ShortEquityAndIndexQuote*>(buffer);
    }
};

#pragma pack(pop)
}
