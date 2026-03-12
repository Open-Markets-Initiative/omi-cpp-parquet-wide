#pragma once

#include <memory>

#include "fields/EventType.hpp"
#include "fields/AdministrativeMessageType.hpp"
#include "fields/MessageIndicator.hpp"
#include "fields/TransactionId.hpp"
#include "fields/ParticipantReferenceNumber.hpp"
#include "fields/MessageDataLength.hpp"
#include "fields/ControlMessageType.hpp"
#include "fields/EquityAndIndexLastSaleMessageType.hpp"
#include "fields/SecuritySymbol.hpp"
#include "fields/Reserved1.hpp"
#include "fields/ExpirationMonth.hpp"
#include "fields/ExpirationDay.hpp"
#include "fields/ExpirationYear.hpp"
#include "fields/StrikePriceDenominatorCode.hpp"
#include "fields/StrikePrice.hpp"
#include "fields/Volume.hpp"
#include "fields/PremiumPriceDenominatorCode.hpp"
#include "fields/PremiumPrice.hpp"
#include "fields/TradeIdentifier.hpp"
#include "fields/Reserved4.hpp"
#include "fields/OpenInterestMessageType.hpp"
#include "fields/OpenInterestVolume.hpp"
#include "fields/EquityAndIndexEndOfDaySummaryMessageType.hpp"
#include "fields/OpenPrice.hpp"
#include "fields/HighPrice.hpp"
#include "fields/LowPrice.hpp"
#include "fields/LastPrice.hpp"
#include "fields/NetChange.hpp"
#include "fields/UnderlyingPriceDenominatorCode.hpp"
#include "fields/UnderlyingPrice.hpp"
#include "fields/BidPrice.hpp"
#include "fields/OfferPrice.hpp"
#include "fields/LongEquityAndIndexQuoteMessageType.hpp"
#include "fields/BboIndicator.hpp"
#include "fields/BidSize.hpp"
#include "fields/OfferSize.hpp"
#include "fields/ShortEquityAndIndexQuoteMessageType.hpp"
#include "fields/SecuritySymbolShort.hpp"
#include "fields/StrikePriceShort.hpp"
#include "fields/BidPriceShort.hpp"
#include "fields/BidSizeShort.hpp"
#include "fields/OfferPriceShort.hpp"
#include "fields/OfferSizeShort.hpp"
#include "fields/UnderlyingValueMessageType.hpp"
#include "fields/IndexValueDenominatorCode.hpp"
#include "fields/IndexValue.hpp"
#include "fields/BidIndexValue.hpp"
#include "fields/OfferIndexValue.hpp"
#include "fields/BestBidParticipantId.hpp"
#include "fields/BestBidDenominatorCode.hpp"
#include "fields/BestBidPrice.hpp"
#include "fields/BestBidSize.hpp"
#include "fields/BestOfferParticipantId.hpp"
#include "fields/BestOfferDenominatorCode.hpp"
#include "fields/BestOfferPrice.hpp"
#include "fields/BestOfferSize.hpp"

namespace siac {
struct ArrowRecord {

    EventType event_type;
    AdministrativeMessageType administrative_message_type;
    MessageIndicator message_indicator;
    TransactionId transaction_id;
    ParticipantReferenceNumber participant_reference_number;
    MessageDataLength message_data_length;
    ControlMessageType control_message_type;
    EquityAndIndexLastSaleMessageType equity_and_index_last_sale_message_type;
    SecuritySymbol security_symbol;
    Reserved1 reserved_1;
    ExpirationMonth expiration_month;
    ExpirationDay expiration_day;
    ExpirationYear expiration_year;
    StrikePriceDenominatorCode strike_price_denominator_code;
    StrikePrice strike_price;
    Volume volume;
    PremiumPriceDenominatorCode premium_price_denominator_code;
    PremiumPrice premium_price;
    TradeIdentifier trade_identifier;
    Reserved4 reserved_4;
    OpenInterestMessageType open_interest_message_type;
    OpenInterestVolume open_interest_volume;
    EquityAndIndexEndOfDaySummaryMessageType equity_and_index_end_of_day_summary_message_type;
    OpenPrice open_price;
    HighPrice high_price;
    LowPrice low_price;
    LastPrice last_price;
    NetChange net_change;
    UnderlyingPriceDenominatorCode underlying_price_denominator_code;
    UnderlyingPrice underlying_price;
    BidPrice bid_price;
    OfferPrice offer_price;
    LongEquityAndIndexQuoteMessageType long_equity_and_index_quote_message_type;
    BboIndicator bbo_indicator;
    BidSize bid_size;
    OfferSize offer_size;
    ShortEquityAndIndexQuoteMessageType short_equity_and_index_quote_message_type;
    SecuritySymbolShort security_symbol_short;
    StrikePriceShort strike_price_short;
    BidPriceShort bid_price_short;
    BidSizeShort bid_size_short;
    OfferPriceShort offer_price_short;
    OfferSizeShort offer_size_short;
    UnderlyingValueMessageType underlying_value_message_type;
    IndexValueDenominatorCode index_value_denominator_code;
    IndexValue index_value;
    BidIndexValue bid_index_value;
    OfferIndexValue offer_index_value;
    BestBidParticipantId best_bid_participant_id;
    BestBidDenominatorCode best_bid_denominator_code;
    BestBidPrice best_bid_price;
    BestBidSize best_bid_size;
    BestOfferParticipantId best_offer_participant_id;
    BestOfferDenominatorCode best_offer_denominator_code;
    BestOfferPrice best_offer_price;
    BestOfferSize best_offer_size;

    ArrowRecord() = default;

    // parquet record reset
    void reset() {
        event_type.reset();
        administrative_message_type.reset();
        message_indicator.reset();
        transaction_id.reset();
        participant_reference_number.reset();
        message_data_length.reset();
        control_message_type.reset();
        equity_and_index_last_sale_message_type.reset();
        security_symbol.reset();
        reserved_1.reset();
        expiration_month.reset();
        expiration_day.reset();
        expiration_year.reset();
        strike_price_denominator_code.reset();
        strike_price.reset();
        volume.reset();
        premium_price_denominator_code.reset();
        premium_price.reset();
        trade_identifier.reset();
        reserved_4.reset();
        open_interest_message_type.reset();
        open_interest_volume.reset();
        equity_and_index_end_of_day_summary_message_type.reset();
        open_price.reset();
        high_price.reset();
        low_price.reset();
        last_price.reset();
        net_change.reset();
        underlying_price_denominator_code.reset();
        underlying_price.reset();
        bid_price.reset();
        offer_price.reset();
        long_equity_and_index_quote_message_type.reset();
        bbo_indicator.reset();
        bid_size.reset();
        offer_size.reset();
        short_equity_and_index_quote_message_type.reset();
        security_symbol_short.reset();
        strike_price_short.reset();
        bid_price_short.reset();
        bid_size_short.reset();
        offer_price_short.reset();
        offer_size_short.reset();
        underlying_value_message_type.reset();
        index_value_denominator_code.reset();
        index_value.reset();
        bid_index_value.reset();
        offer_index_value.reset();
        best_bid_participant_id.reset();
        best_bid_denominator_code.reset();
        best_bid_price.reset();
        best_bid_size.reset();
        best_offer_participant_id.reset();
        best_offer_denominator_code.reset();
        best_offer_price.reset();
        best_offer_size.reset();
    }

    // arrow schema
    static auto schema() {
        return arrow::schema( {
            EventType::column(),
            AdministrativeMessageType::column(),
            MessageIndicator::column(),
            TransactionId::column(),
            ParticipantReferenceNumber::column(),
            MessageDataLength::column(),
            ControlMessageType::column(),
            EquityAndIndexLastSaleMessageType::column(),
            SecuritySymbol::column(),
            Reserved1::column(),
            ExpirationMonth::column(),
            ExpirationDay::column(),
            ExpirationYear::column(),
            StrikePriceDenominatorCode::column(),
            StrikePrice::column(),
            Volume::column(),
            PremiumPriceDenominatorCode::column(),
            PremiumPrice::column(),
            TradeIdentifier::column(),
            Reserved4::column(),
            OpenInterestMessageType::column(),
            OpenInterestVolume::column(),
            EquityAndIndexEndOfDaySummaryMessageType::column(),
            OpenPrice::column(),
            HighPrice::column(),
            LowPrice::column(),
            LastPrice::column(),
            NetChange::column(),
            UnderlyingPriceDenominatorCode::column(),
            UnderlyingPrice::column(),
            BidPrice::column(),
            OfferPrice::column(),
            LongEquityAndIndexQuoteMessageType::column(),
            BboIndicator::column(),
            BidSize::column(),
            OfferSize::column(),
            ShortEquityAndIndexQuoteMessageType::column(),
            SecuritySymbolShort::column(),
            StrikePriceShort::column(),
            BidPriceShort::column(),
            BidSizeShort::column(),
            OfferPriceShort::column(),
            OfferSizeShort::column(),
            UnderlyingValueMessageType::column(),
            IndexValueDenominatorCode::column(),
            IndexValue::column(),
            BidIndexValue::column(),
            OfferIndexValue::column(),
            BestBidParticipantId::column(),
            BestBidDenominatorCode::column(),
            BestBidPrice::column(),
            BestBidSize::column(),
            BestOfferParticipantId::column(),
            BestOfferDenominatorCode::column(),
            BestOfferPrice::column(),
            BestOfferSize::column()
        } );
    }
};
}
