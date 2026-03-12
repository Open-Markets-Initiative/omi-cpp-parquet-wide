#pragma once

#include "../types/LongEquityAndIndexQuoteMessageType.hpp"
#include "../types/BboIndicator.hpp"
#include "../types/TransactionId.hpp"
#include "../types/ParticipantReferenceNumber.hpp"
#include "../types/SecuritySymbol.hpp"
#include "../types/Reserved1.hpp"
#include "../structs/ExpirationBlock.hpp"
#include "../types/StrikePriceDenominatorCode.hpp"
#include "../types/StrikePrice.hpp"
#include "../types/PremiumPriceDenominatorCode.hpp"
#include "../types/BidPrice.hpp"
#include "../types/BidSize.hpp"
#include "../types/OfferPrice.hpp"
#include "../types/OfferSize.hpp"
#include "../structs/BestBidAppendage.hpp"
#include "../structs/BestOfferAppendage.hpp"
#include "../structs/BestBidAndOfferAppendage.hpp"

namespace siac::opra::recipient::obi::v6_2 {

#pragma pack(push, 1)

struct LongEquityAndIndexQuote {

    LongEquityAndIndexQuoteMessageType long_equity_and_index_quote_message_type;
    BboIndicator bbo_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    SecuritySymbol security_symbol;
    Reserved1 reserved_1;
    ExpirationBlock expiration_block;
    StrikePriceDenominatorCode strike_price_denominator_code;
    StrikePrice strike_price;
    PremiumPriceDenominatorCode premium_price_denominator_code;
    BidPrice bid_price;
    BidSize bid_size;
    OfferPrice offer_price;
    OfferSize offer_size;
    BestBidAppendage best_bid_appendage;
    BestOfferAppendage best_offer_appendage;
    BestBidAndOfferAppendage best_bid_and_offer_appendage;

    // parse method
    static LongEquityAndIndexQuote* parse(std::byte* buffer) {
        return reinterpret_cast<LongEquityAndIndexQuote*>(buffer);
    }

    // parse method const
    static const LongEquityAndIndexQuote* parse(const std::byte* buffer) {
        return reinterpret_cast<const LongEquityAndIndexQuote*>(buffer);
    }
};

#pragma pack(pop)
}
