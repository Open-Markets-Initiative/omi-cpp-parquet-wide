#pragma once

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/iterators/MessageIterator.hpp"
#include "../parquet/Writer.hpp"

namespace iex::equities::tops::iextp::v1_6_6 {

///////////////////////////////////////////////////////////////////////
// Iex IexTp C++ parquet conversion manager
///////////////////////////////////////////////////////////////////////

// itch to parquet manager
struct Manager {

    MessageIterator iextp;
    packet::Parser& parser;
    iex::Writer& record;
    const conversion::Options& options;

    explicit Manager(const conversion::Options& options, packet::Parser& parser, iex::Writer& record)
     : parser{ parser }, record{ record }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        iextp.initialize(frame.payload, frame.payload_len);

        if (iextp.message_count == 0) {
            return;
        }

        while (iextp.next()) {
            process(iextp.message, iextp.message_type);
        }

        packet_end();
    }

    void process(const std::byte* pointer, const char message_type) {
        switch (message_type) {
            case 'S':
                process_system_event_message(pointer);
                break;

            case 'D':
                process_security_directory_message(pointer);
                break;

            case 'H':
                process_trading_status_message(pointer);
                break;

            case 'I':
                process_retail_liquidity_indicator_message(pointer);
                break;

            case 'O':
                process_operational_halt_status_message(pointer);
                break;

            case 'P':
                process_short_sale_price_test_status_message(pointer);
                break;

            case 'Q':
                process_quote_update_message(pointer);
                break;

            case 'T':
                process_trade_report_message(pointer);
                break;

            case 'X':
                process_official_price_message(pointer);
                break;

            case 'B':
                process_trade_break_message(pointer);
                break;

            case 'A':
                process_auction_information_message(pointer);
                break;

            default:
                break;
        }
    }

    void process_system_event_message(const std::byte* pointer) {
        const auto message = SystemEventMessage::parse(pointer);

        record.event_type.set("System Event Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.system_event.set(message->system_event.get());
        record.timestamp.set(message->timestamp.get());

        record.write();
        record.reset();
    }

    void process_security_directory_message(const std::byte* pointer) {
        const auto message = SecurityDirectoryMessage::parse(pointer);

        record.event_type.set("Security Directory Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.round_lot_size.set(message->round_lot_size.get());
        record.adjusted_poc_price.set(message->adjusted_poc_price.get());
        record.luld_tier.set(message->luld_tier.get());

        record.write();
        record.reset();
    }

    void process_trading_status_message(const std::byte* pointer) {
        const auto message = TradingStatusMessage::parse(pointer);

        record.event_type.set("Trading Status Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.trading_status.set(message->trading_status.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.reason.set(message->reason.get());

        record.write();
        record.reset();
    }

    void process_retail_liquidity_indicator_message(const std::byte* pointer) {
        const auto message = RetailLiquidityIndicatorMessage::parse(pointer);

        record.event_type.set("Retail Liquidity Indicator Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.retail_liquidity_indicator.set(message->retail_liquidity_indicator.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());

        record.write();
        record.reset();
    }

    void process_operational_halt_status_message(const std::byte* pointer) {
        const auto message = OperationalHaltStatusMessage::parse(pointer);

        record.event_type.set("Operational Halt Status Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.operational_halt_status.set(message->operational_halt_status.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());

        record.write();
        record.reset();
    }

    void process_short_sale_price_test_status_message(const std::byte* pointer) {
        const auto message = ShortSalePriceTestStatusMessage::parse(pointer);

        record.event_type.set("Short Sale Price Test Status Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.short_sale_price_test_status.set(message->short_sale_price_test_status.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.detail.set(message->detail.get());

        record.write();
        record.reset();
    }

    void process_quote_update_message(const std::byte* pointer) {
        const auto message = QuoteUpdateMessage::parse(pointer);

        record.event_type.set("Quote Update Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.bid_size.set(message->bid_size.get());
        record.bid_price.set(message->bid_price.get());
        record.ask_price.set(message->ask_price.get());
        record.ask_size.set(message->ask_size.get());

        record.write();
        record.reset();
    }

    void process_trade_report_message(const std::byte* pointer) {
        const auto message = TradeReportMessage::parse(pointer);

        record.event_type.set("Trade Report Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.size.set(message->size.get());
        record.price.set(message->price.get());
        record.trade_id.set(message->trade_id.get());

        record.write();
        record.reset();
    }

    void process_official_price_message(const std::byte* pointer) {
        const auto message = OfficialPriceMessage::parse(pointer);

        record.event_type.set("Official Price Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.price_type.set(message->price_type.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.official_price.set(message->official_price.get());

        record.write();
        record.reset();
    }

    void process_trade_break_message(const std::byte* pointer) {
        const auto message = TradeBreakMessage::parse(pointer);

        record.event_type.set("Trade Break Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.size.set(message->size.get());
        record.price.set(message->price.get());
        record.trade_id.set(message->trade_id.get());

        record.write();
        record.reset();
    }

    void process_auction_information_message(const std::byte* pointer) {
        const auto message = AuctionInformationMessage::parse(pointer);

        record.event_type.set("Auction Information Message");
        record.version.set(iextp.iextp_header->version.get());
        record.message_protocol_id.set(iextp.iextp_header->message_protocol_id.get());
        record.channel_id.set(iextp.iextp_header->channel_id.get());
        record.session_id.set(iextp.iextp_header->session_id.get());
        record.payload_length.set(iextp.iextp_header->payload_length.get());
        record.stream_offset.set(iextp.iextp_header->stream_offset.get());
        record.first_message_sequence_number.set(iextp.iextp_header->first_message_sequence_number.get());
        record.send_time.set(iextp.iextp_header->send_time.get());
        record.auction_type.set(message->auction_type.get());
        record.timestamp.set(message->timestamp.get());
        record.symbol.set(message->symbol.get());
        record.paired_shares.set(message->paired_shares.get());
        record.reference_price.set(message->reference_price.get());
        record.indicative_clearing_price.set(message->indicative_clearing_price.get());
        record.imbalance_shares.set(message->imbalance_shares.get());
        record.imbalance_side.set(message->imbalance_side.get());
        record.extension_number.set(message->extension_number.get());
        record.scheduled_auction_time.set(message->scheduled_auction_time.get());
        record.auction_book_clearing_price.set(message->auction_book_clearing_price.get());
        record.collar_reference_price.set(message->collar_reference_price.get());
        record.lower_auction_collar.set(message->lower_auction_collar.get());
        record.upper_auction_collar.set(message->upper_auction_collar.get());

        record.write();
        record.reset();
    }

    // packet end action
    void packet_end() {
    }
};
}
