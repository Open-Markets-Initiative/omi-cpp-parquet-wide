#pragma once

#include <memory>

#include "fields/EventType.hpp"
#include "fields/Version.hpp"
#include "fields/MessageProtocolId.hpp"
#include "fields/ChannelId.hpp"
#include "fields/SessionId.hpp"
#include "fields/PayloadLength.hpp"
#include "fields/StreamOffset.hpp"
#include "fields/FirstMessageSequenceNumber.hpp"
#include "fields/SendTime.hpp"
#include "fields/SystemEvent.hpp"
#include "fields/Timestamp.hpp"
#include "fields/Symbol.hpp"
#include "fields/RoundLotSize.hpp"
#include "fields/AdjustedPocPrice.hpp"
#include "fields/LuldTier.hpp"
#include "fields/TradingStatus.hpp"
#include "fields/Reason.hpp"
#include "fields/RetailLiquidityIndicator.hpp"
#include "fields/OperationalHaltStatus.hpp"
#include "fields/ShortSalePriceTestStatus.hpp"
#include "fields/Detail.hpp"
#include "fields/BidSize.hpp"
#include "fields/BidPrice.hpp"
#include "fields/AskPrice.hpp"
#include "fields/AskSize.hpp"
#include "fields/Size.hpp"
#include "fields/Price.hpp"
#include "fields/TradeId.hpp"
#include "fields/PriceType.hpp"
#include "fields/OfficialPrice.hpp"
#include "fields/AuctionType.hpp"
#include "fields/PairedShares.hpp"
#include "fields/ReferencePrice.hpp"
#include "fields/IndicativeClearingPrice.hpp"
#include "fields/ImbalanceShares.hpp"
#include "fields/ImbalanceSide.hpp"
#include "fields/ExtensionNumber.hpp"
#include "fields/ScheduledAuctionTime.hpp"
#include "fields/AuctionBookClearingPrice.hpp"
#include "fields/CollarReferencePrice.hpp"
#include "fields/LowerAuctionCollar.hpp"
#include "fields/UpperAuctionCollar.hpp"

namespace iex {
struct ArrowRecord {

    EventType event_type;
    Version version;
    MessageProtocolId message_protocol_id;
    ChannelId channel_id;
    SessionId session_id;
    PayloadLength payload_length;
    StreamOffset stream_offset;
    FirstMessageSequenceNumber first_message_sequence_number;
    SendTime send_time;
    SystemEvent system_event;
    Timestamp timestamp;
    Symbol symbol;
    RoundLotSize round_lot_size;
    AdjustedPocPrice adjusted_poc_price;
    LuldTier luld_tier;
    TradingStatus trading_status;
    Reason reason;
    RetailLiquidityIndicator retail_liquidity_indicator;
    OperationalHaltStatus operational_halt_status;
    ShortSalePriceTestStatus short_sale_price_test_status;
    Detail detail;
    BidSize bid_size;
    BidPrice bid_price;
    AskPrice ask_price;
    AskSize ask_size;
    Size size;
    Price price;
    TradeId trade_id;
    PriceType price_type;
    OfficialPrice official_price;
    AuctionType auction_type;
    PairedShares paired_shares;
    ReferencePrice reference_price;
    IndicativeClearingPrice indicative_clearing_price;
    ImbalanceShares imbalance_shares;
    ImbalanceSide imbalance_side;
    ExtensionNumber extension_number;
    ScheduledAuctionTime scheduled_auction_time;
    AuctionBookClearingPrice auction_book_clearing_price;
    CollarReferencePrice collar_reference_price;
    LowerAuctionCollar lower_auction_collar;
    UpperAuctionCollar upper_auction_collar;

    ArrowRecord() = default;

    // parquet record reset
    void reset() {
        event_type.reset();
        version.reset();
        message_protocol_id.reset();
        channel_id.reset();
        session_id.reset();
        payload_length.reset();
        stream_offset.reset();
        first_message_sequence_number.reset();
        send_time.reset();
        system_event.reset();
        timestamp.reset();
        symbol.reset();
        round_lot_size.reset();
        adjusted_poc_price.reset();
        luld_tier.reset();
        trading_status.reset();
        reason.reset();
        retail_liquidity_indicator.reset();
        operational_halt_status.reset();
        short_sale_price_test_status.reset();
        detail.reset();
        bid_size.reset();
        bid_price.reset();
        ask_price.reset();
        ask_size.reset();
        size.reset();
        price.reset();
        trade_id.reset();
        price_type.reset();
        official_price.reset();
        auction_type.reset();
        paired_shares.reset();
        reference_price.reset();
        indicative_clearing_price.reset();
        imbalance_shares.reset();
        imbalance_side.reset();
        extension_number.reset();
        scheduled_auction_time.reset();
        auction_book_clearing_price.reset();
        collar_reference_price.reset();
        lower_auction_collar.reset();
        upper_auction_collar.reset();
    }

    // arrow schema
    static auto schema() {
        return arrow::schema( {
            EventType::column(),
            Version::column(),
            MessageProtocolId::column(),
            ChannelId::column(),
            SessionId::column(),
            PayloadLength::column(),
            StreamOffset::column(),
            FirstMessageSequenceNumber::column(),
            SendTime::column(),
            SystemEvent::column(),
            Timestamp::column(),
            Symbol::column(),
            RoundLotSize::column(),
            AdjustedPocPrice::column(),
            LuldTier::column(),
            TradingStatus::column(),
            Reason::column(),
            RetailLiquidityIndicator::column(),
            OperationalHaltStatus::column(),
            ShortSalePriceTestStatus::column(),
            Detail::column(),
            BidSize::column(),
            BidPrice::column(),
            AskPrice::column(),
            AskSize::column(),
            Size::column(),
            Price::column(),
            TradeId::column(),
            PriceType::column(),
            OfficialPrice::column(),
            AuctionType::column(),
            PairedShares::column(),
            ReferencePrice::column(),
            IndicativeClearingPrice::column(),
            ImbalanceShares::column(),
            ImbalanceSide::column(),
            ExtensionNumber::column(),
            ScheduledAuctionTime::column(),
            AuctionBookClearingPrice::column(),
            CollarReferencePrice::column(),
            LowerAuctionCollar::column(),
            UpperAuctionCollar::column()
        } );
    }
};
}
