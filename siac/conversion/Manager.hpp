#pragma once

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/iterators/MessageIterator.hpp"
#include "../parquet/Writer.hpp"

namespace siac::opra::recipient::obi::v6_2 {

///////////////////////////////////////////////////////////////////////
// Siac Obi C++ parquet conversion manager
///////////////////////////////////////////////////////////////////////

// itch to parquet manager
struct Manager {

    MessageIterator obi;
    packet::Parser& parser;
    siac::Writer& record;
    const conversion::Options& options;

    explicit Manager(const conversion::Options& options, packet::Parser& parser, siac::Writer& record)
     : parser{ parser }, record{ record }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        obi.initialize(frame.payload);

        while (obi.next()) {
            const auto* header = MessageHeader::parse(obi.entry);
            process(obi.entry + sizeof(MessageHeader), header->message_category.get());
        }

        packet_end();
    }

    void process(const std::byte* pointer, const char message_category) {
        switch (message_category) {
            case 'C':
                process_administrative(pointer);
                break;

            case 'H':
                process_control(pointer);
                break;

            case 'a':
                process_equity_and_index_last_sale(pointer);
                break;

            case 'd':
                process_open_interest(pointer);
                break;

            case 'f':
                process_equity_and_index_end_of_day_summary(pointer);
                break;

            case 'k':
                process_long_equity_and_index_quote(pointer);
                break;

            case 'q':
                process_short_equity_and_index_quote(pointer);
                break;

            default:
                break;
        }
    }

    void process_administrative(const std::byte* pointer) {
        const auto message = Administrative::parse(pointer);

        record.event_type.set("Administrative");
        record.administrative_message_type.set(message->administrative_message_type.get());
        record.message_indicator.set(message->message_indicator.get());
        record.transaction_id.set(message->transaction_id.get());
        record.participant_reference_number.set(message->participant_reference_number.get());
        record.message_data_length.set(message->message_data_length.get());

        record.write();
        record.reset();
    }

    void process_control(const std::byte* pointer) {
        const auto message = Control::parse(pointer);

        record.event_type.set("Control");
        record.control_message_type.set(message->control_message_type.get());
        record.message_indicator.set(message->message_indicator.get());
        record.transaction_id.set(message->transaction_id.get());
        record.participant_reference_number.set(message->participant_reference_number.get());

        record.write();
        record.reset();
    }

    void process_equity_and_index_last_sale(const std::byte* pointer) {
        const auto message = EquityAndIndexLastSale::parse(pointer);

        record.event_type.set("Equity And Index Last Sale");
        record.equity_and_index_last_sale_message_type.set(message->equity_and_index_last_sale_message_type.get());
        record.message_indicator.set(message->message_indicator.get());
        record.transaction_id.set(message->transaction_id.get());
        record.participant_reference_number.set(message->participant_reference_number.get());
        record.security_symbol.set(message->security_symbol.get());
        record.reserved_1.set(message->reserved_1.get());
        record.strike_price_denominator_code.set(message->strike_price_denominator_code.get());
        record.strike_price.set(message->strike_price.get());
        record.volume.set(message->volume.get());
        record.premium_price_denominator_code.set(message->premium_price_denominator_code.get());
        record.premium_price.set(message->premium_price.get());
        record.trade_identifier.set(message->trade_identifier.get());
        record.reserved_4.set(message->reserved_4.get());

        record.write();
        record.reset();
    }

    void process_open_interest(const std::byte* pointer) {
        const auto message = OpenInterest::parse(pointer);

        record.event_type.set("Open Interest");
        record.open_interest_message_type.set(message->open_interest_message_type.get());
        record.message_indicator.set(message->message_indicator.get());
        record.transaction_id.set(message->transaction_id.get());
        record.participant_reference_number.set(message->participant_reference_number.get());
        record.security_symbol.set(message->security_symbol.get());
        record.reserved_1.set(message->reserved_1.get());
        record.strike_price_denominator_code.set(message->strike_price_denominator_code.get());
        record.strike_price.set(message->strike_price.get());
        record.open_interest_volume.set(message->open_interest_volume.get());

        record.write();
        record.reset();
    }

    void process_equity_and_index_end_of_day_summary(const std::byte* pointer) {
        const auto message = EquityAndIndexEndOfDaySummary::parse(pointer);

        record.event_type.set("Equity And Index End Of Day Summary");
        record.equity_and_index_end_of_day_summary_message_type.set(message->equity_and_index_end_of_day_summary_message_type.get());
        record.message_indicator.set(message->message_indicator.get());
        record.transaction_id.set(message->transaction_id.get());
        record.participant_reference_number.set(message->participant_reference_number.get());
        record.security_symbol.set(message->security_symbol.get());
        record.reserved_1.set(message->reserved_1.get());
        record.strike_price_denominator_code.set(message->strike_price_denominator_code.get());
        record.strike_price.set(message->strike_price.get());
        record.volume.set(message->volume.get());
        record.open_interest_volume.set(message->open_interest_volume.get());
        record.premium_price_denominator_code.set(message->premium_price_denominator_code.get());
        record.open_price.set(message->open_price.get());
        record.high_price.set(message->high_price.get());
        record.low_price.set(message->low_price.get());
        record.last_price.set(message->last_price.get());
        record.net_change.set(message->net_change.get());
        record.underlying_price_denominator_code.set(message->underlying_price_denominator_code.get());
        record.underlying_price.set(message->underlying_price.get());
        record.bid_price.set(message->bid_price.get());
        record.offer_price.set(message->offer_price.get());

        record.write();
        record.reset();
    }

    void process_long_equity_and_index_quote(const std::byte* pointer) {
        const auto message = LongEquityAndIndexQuote::parse(pointer);

        record.event_type.set("Long Equity And Index Quote");
        record.long_equity_and_index_quote_message_type.set(message->long_equity_and_index_quote_message_type.get());
        record.bbo_indicator.set(message->bbo_indicator.get());
        record.transaction_id.set(message->transaction_id.get());
        record.participant_reference_number.set(message->participant_reference_number.get());
        record.security_symbol.set(message->security_symbol.get());
        record.reserved_1.set(message->reserved_1.get());
        record.strike_price_denominator_code.set(message->strike_price_denominator_code.get());
        record.strike_price.set(message->strike_price.get());
        record.premium_price_denominator_code.set(message->premium_price_denominator_code.get());
        record.bid_price.set(message->bid_price.get());
        record.bid_size.set(message->bid_size.get());
        record.offer_price.set(message->offer_price.get());
        record.offer_size.set(message->offer_size.get());
        if (message->bbo_indicator.get() == 'M' || message->bbo_indicator.get() == 'N' || message->bbo_indicator.get() == 'P') {
            record.best_bid_participant_id.set(message->best_bid_appendage.best_bid_participant_id.get());
            record.best_bid_denominator_code.set(message->best_bid_appendage.best_bid_denominator_code.get());
            record.best_bid_price.set(message->best_bid_appendage.best_bid_price.get());
            record.best_bid_size.set(message->best_bid_appendage.best_bid_size.get());
        }
        if (message->bbo_indicator.get() == 'C' || message->bbo_indicator.get() == 'G' || message->bbo_indicator.get() == 'K') {
            record.best_offer_participant_id.set(message->best_offer_appendage.best_offer_participant_id.get());
            record.best_offer_denominator_code.set(message->best_offer_appendage.best_offer_denominator_code.get());
            record.best_offer_price.set(message->best_offer_appendage.best_offer_price.get());
            record.best_offer_size.set(message->best_offer_appendage.best_offer_size.get());
        }
        if (message->bbo_indicator.get() == 'O') {
            record.best_bid_participant_id.set(message->best_bid_and_offer_appendage.best_bid_participant_id.get());
            record.best_bid_denominator_code.set(message->best_bid_and_offer_appendage.best_bid_denominator_code.get());
            record.best_bid_price.set(message->best_bid_and_offer_appendage.best_bid_price.get());
            record.best_bid_size.set(message->best_bid_and_offer_appendage.best_bid_size.get());
            record.best_offer_participant_id.set(message->best_bid_and_offer_appendage.best_offer_participant_id.get());
            record.best_offer_denominator_code.set(message->best_bid_and_offer_appendage.best_offer_denominator_code.get());
            record.best_offer_price.set(message->best_bid_and_offer_appendage.best_offer_price.get());
            record.best_offer_size.set(message->best_bid_and_offer_appendage.best_offer_size.get());
        }

        record.write();
        record.reset();
    }

    void process_short_equity_and_index_quote(const std::byte* pointer) {
        const auto message = ShortEquityAndIndexQuote::parse(pointer);

        record.event_type.set("Short Equity And Index Quote");
        record.short_equity_and_index_quote_message_type.set(message->short_equity_and_index_quote_message_type.get());
        record.bbo_indicator.set(message->bbo_indicator.get());
        record.transaction_id.set(message->transaction_id.get());
        record.participant_reference_number.set(message->participant_reference_number.get());
        record.security_symbol_short.set(message->security_symbol_short.get());
        record.strike_price_short.set(message->strike_price_short.get());
        record.bid_price_short.set(message->bid_price_short.get());
        record.bid_size_short.set(message->bid_size_short.get());
        record.offer_price_short.set(message->offer_price_short.get());
        record.offer_size_short.set(message->offer_size_short.get());
        if (message->bbo_indicator.get() == 'M' || message->bbo_indicator.get() == 'N' || message->bbo_indicator.get() == 'P') {
            record.best_bid_participant_id.set(message->best_bid_appendage.best_bid_participant_id.get());
            record.best_bid_denominator_code.set(message->best_bid_appendage.best_bid_denominator_code.get());
            record.best_bid_price.set(message->best_bid_appendage.best_bid_price.get());
            record.best_bid_size.set(message->best_bid_appendage.best_bid_size.get());
        }
        if (message->bbo_indicator.get() == 'C' || message->bbo_indicator.get() == 'G' || message->bbo_indicator.get() == 'K') {
            record.best_offer_participant_id.set(message->best_offer_appendage.best_offer_participant_id.get());
            record.best_offer_denominator_code.set(message->best_offer_appendage.best_offer_denominator_code.get());
            record.best_offer_price.set(message->best_offer_appendage.best_offer_price.get());
            record.best_offer_size.set(message->best_offer_appendage.best_offer_size.get());
        }

        record.write();
        record.reset();
    }

    // packet end action
    void packet_end() {
    }
};
}
