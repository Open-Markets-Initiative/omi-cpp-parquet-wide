#pragma once

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/iterators/MessageIterator.hpp"
#include "../protocol/iterators/MessageBlockIterator.hpp"
#include "../parquet/Writer.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {

///////////////////////////////////////////////////////////////////////
// Nasdaq Itch C++ parquet conversion manager
///////////////////////////////////////////////////////////////////////

// itch to parquet manager
struct Manager {

    MessageIterator itch;
    packet::Parser& parser;
    nasdaq::Writer& record;
    const conversion::Options& options;

    explicit Manager(const conversion::Options& options, packet::Parser& parser, nasdaq::Writer& record)
     : parser{ parser }, record{ record }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        itch.initialize(frame.payload);

        while (itch.next()) {
            process(itch.message, itch.message_type);
        }

        packet_end();
    }

    void process(const std::byte* pointer, const char message_type) {
        switch (message_type) {
            case 0:
                process_heartbeat(pointer);
                break;

            case 65535:
                process_end_of_session(pointer);
                break;

            case 'S':
                process_system_event_message(pointer);
                break;

            case 'R':
                process_stock_directory_message(pointer);
                break;

            case 'H':
                process_stock_trading_action_message(pointer);
                break;

            case 'Y':
                process_reg_sho_short_sale_price_test_restricted_indicator_message(pointer);
                break;

            case 'L':
                process_market_participant_position_message(pointer);
                break;

            case 'V':
                process_mwcb_decline_level_message(pointer);
                break;

            case 'W':
                process_mwcb_status_level_message(pointer);
                break;

            case 'K':
                process_ipo_quoting_period_update(pointer);
                break;

            case 'J':
                process_luld_auction_collar_message(pointer);
                break;

            case 'h':
                process_operational_halt_message(pointer);
                break;

            case 'A':
                process_add_order_no_mpid_attribution_message(pointer);
                break;

            case 'F':
                process_add_order_with_mpid_attribution_message(pointer);
                break;

            case 'E':
                process_order_executed_message(pointer);
                break;

            case 'C':
                process_order_executed_with_price_message(pointer);
                break;

            case 'X':
                process_order_cancel_message(pointer);
                break;

            case 'D':
                process_order_delete_message(pointer);
                break;

            case 'U':
                process_order_replace_message(pointer);
                break;

            case 'P':
                process_non_cross_trade_message(pointer);
                break;

            case 'Q':
                process_cross_trade_message(pointer);
                break;

            case 'B':
                process_broken_trade_message(pointer);
                break;

            case 'I':
                process_net_order_imbalance_indicator_message(pointer);
                break;

            case 'N':
                process_retail_price_improvement_indicator_message(pointer);
                break;

            case 'O':
                process_direct_listing_with_capital_raise_price_discovery_message(pointer);
                break;

            default:
                break;
        }
    }

    void process_heartbeat(const std::byte* pointer) {
        record.event_type.set("Heartbeat");

        record.write();
        record.reset();
    }

    void process_end_of_session(const std::byte* pointer) {
        record.event_type.set("End Of Session");

        record.write();
        record.reset();
    }

    void process_system_event_message(const std::byte* pointer) {
        const auto message = SystemEventMessage::parse(pointer);

        record.event_type.set("System Event Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.event_code.set(message->event_code.get());

        record.write();
        record.reset();
    }

    void process_stock_directory_message(const std::byte* pointer) {
        const auto message = StockDirectoryMessage::parse(pointer);

        record.event_type.set("Stock Directory Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.market_category.set(message->market_category.get());
        record.financial_status_indicator.set(message->financial_status_indicator.get());
        record.round_lot_size.set(message->round_lot_size.get());
        record.round_lots_only.set(message->round_lots_only.get());
        record.issue_classification.set(message->issue_classification.get());
        record.issue_sub_type.set(message->issue_sub_type.get());
        record.authenticity.set(message->authenticity.get());
        record.short_sale_threshold_indicator.set(message->short_sale_threshold_indicator.get());
        record.ipo_flag.set(message->ipo_flag.get());
        record.luld_reference_price_tier.set(message->luld_reference_price_tier.get());
        record.etp_flag.set(message->etp_flag.get());
        record.etp_leverage_factor.set(message->etp_leverage_factor.get());
        record.inverse_indicator.set(message->inverse_indicator.get());

        record.write();
        record.reset();
    }

    void process_stock_trading_action_message(const std::byte* pointer) {
        const auto message = StockTradingActionMessage::parse(pointer);

        record.event_type.set("Stock Trading Action Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.trading_state.set(message->trading_state.get());
        record.reserved.set(message->reserved.get());
        record.reason_code.set(message->reason_code.get());

        record.write();
        record.reset();
    }

    void process_reg_sho_short_sale_price_test_restricted_indicator_message(const std::byte* pointer) {
        const auto message = RegShoShortSalePriceTestRestrictedIndicatorMessage::parse(pointer);

        record.event_type.set("Reg Sho Short Sale Price Test Restricted Indicator Message");
        record.locate_code.set(message->locate_code.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.reg_sho_action.set(message->reg_sho_action.get());

        record.write();
        record.reset();
    }

    void process_market_participant_position_message(const std::byte* pointer) {
        const auto message = MarketParticipantPositionMessage::parse(pointer);

        record.event_type.set("Market Participant Position Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.mpid.set(message->mpid.get());
        record.stock.set(message->stock.get());
        record.primary_market_maker.set(message->primary_market_maker.get());
        record.market_maker_mode.set(message->market_maker_mode.get());
        record.market_participant_state.set(message->market_participant_state.get());

        record.write();
        record.reset();
    }

    void process_mwcb_decline_level_message(const std::byte* pointer) {
        const auto message = MwcbDeclineLevelMessage::parse(pointer);

        record.event_type.set("Mwcb Decline Level Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.level_1.set(message->level_1.get());
        record.level_2.set(message->level_2.get());
        record.level_3.set(message->level_3.get());

        record.write();
        record.reset();
    }

    void process_mwcb_status_level_message(const std::byte* pointer) {
        const auto message = MwcbStatusLevelMessage::parse(pointer);

        record.event_type.set("Mwcb Status Level Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.breached_level.set(message->breached_level.get());

        record.write();
        record.reset();
    }

    void process_ipo_quoting_period_update(const std::byte* pointer) {
        const auto message = IpoQuotingPeriodUpdate::parse(pointer);

        record.event_type.set("Ipo Quoting Period Update");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.ipo_quotation_release_time.set(message->ipo_quotation_release_time.get());
        record.ipo_quotation_release_qualifier.set(message->ipo_quotation_release_qualifier.get());
        record.ipo_price.set(message->ipo_price.get());

        record.write();
        record.reset();
    }

    void process_luld_auction_collar_message(const std::byte* pointer) {
        const auto message = LuldAuctionCollarMessage::parse(pointer);

        record.event_type.set("Luld Auction Collar Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.auction_collar_reference_price.set(message->auction_collar_reference_price.get());
        record.upper_auction_collar_price.set(message->upper_auction_collar_price.get());
        record.lower_auction_collar_price.set(message->lower_auction_collar_price.get());
        record.auction_collar_extension.set(message->auction_collar_extension.get());

        record.write();
        record.reset();
    }

    void process_operational_halt_message(const std::byte* pointer) {
        const auto message = OperationalHaltMessage::parse(pointer);

        record.event_type.set("Operational Halt Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.market_code.set(message->market_code.get());
        record.operational_halt_action.set(message->operational_halt_action.get());

        record.write();
        record.reset();
    }

    void process_add_order_no_mpid_attribution_message(const std::byte* pointer) {
        const auto message = AddOrderNoMpidAttributionMessage::parse(pointer);

        record.event_type.set("Add Order No Mpid Attribution Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.order_reference_number.set(message->order_reference_number.get());
        record.buy_sell_indicator.set(message->buy_sell_indicator.get());
        record.shares.set(message->shares.get());
        record.stock.set(message->stock.get());
        record.price.set(message->price.get());

        record.write();
        record.reset();
    }

    void process_add_order_with_mpid_attribution_message(const std::byte* pointer) {
        const auto message = AddOrderWithMpidAttributionMessage::parse(pointer);

        record.event_type.set("Add Order With Mpid Attribution Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.order_reference_number.set(message->order_reference_number.get());
        record.buy_sell_indicator.set(message->buy_sell_indicator.get());
        record.shares.set(message->shares.get());
        record.stock.set(message->stock.get());
        record.price.set(message->price.get());
        record.attribution.set(message->attribution.get());

        record.write();
        record.reset();
    }

    void process_order_executed_message(const std::byte* pointer) {
        const auto message = OrderExecutedMessage::parse(pointer);

        record.event_type.set("Order Executed Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.order_reference_number.set(message->order_reference_number.get());
        record.executed_shares.set(message->executed_shares.get());
        record.match_number.set(message->match_number.get());

        record.write();
        record.reset();
    }

    void process_order_executed_with_price_message(const std::byte* pointer) {
        const auto message = OrderExecutedWithPriceMessage::parse(pointer);

        record.event_type.set("Order Executed With Price Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.order_reference_number.set(message->order_reference_number.get());
        record.executed_shares.set(message->executed_shares.get());
        record.match_number.set(message->match_number.get());
        record.printable.set(message->printable.get());
        record.execution_price.set(message->execution_price.get());

        record.write();
        record.reset();
    }

    void process_order_cancel_message(const std::byte* pointer) {
        const auto message = OrderCancelMessage::parse(pointer);

        record.event_type.set("Order Cancel Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.order_reference_number.set(message->order_reference_number.get());
        record.canceled_shares.set(message->canceled_shares.get());

        record.write();
        record.reset();
    }

    void process_order_delete_message(const std::byte* pointer) {
        const auto message = OrderDeleteMessage::parse(pointer);

        record.event_type.set("Order Delete Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.order_reference_number.set(message->order_reference_number.get());

        record.write();
        record.reset();
    }

    void process_order_replace_message(const std::byte* pointer) {
        const auto message = OrderReplaceMessage::parse(pointer);

        record.event_type.set("Order Replace Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.original_order_reference_number.set(message->original_order_reference_number.get());
        record.new_order_reference_number.set(message->new_order_reference_number.get());
        record.shares.set(message->shares.get());
        record.price.set(message->price.get());

        record.write();
        record.reset();
    }

    void process_non_cross_trade_message(const std::byte* pointer) {
        const auto message = NonCrossTradeMessage::parse(pointer);

        record.event_type.set("Non Cross Trade Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.order_reference_number.set(message->order_reference_number.get());
        record.buy_sell_indicator.set(message->buy_sell_indicator.get());
        record.shares.set(message->shares.get());
        record.stock.set(message->stock.get());
        record.price.set(message->price.get());
        record.match_number.set(message->match_number.get());

        record.write();
        record.reset();
    }

    void process_cross_trade_message(const std::byte* pointer) {
        const auto message = CrossTradeMessage::parse(pointer);

        record.event_type.set("Cross Trade Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.cross_shares.set(message->cross_shares.get());
        record.stock.set(message->stock.get());
        record.cross_price.set(message->cross_price.get());
        record.match_number.set(message->match_number.get());
        record.cross_type.set(message->cross_type.get());

        record.write();
        record.reset();
    }

    void process_broken_trade_message(const std::byte* pointer) {
        const auto message = BrokenTradeMessage::parse(pointer);

        record.event_type.set("Broken Trade Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.match_number.set(message->match_number.get());

        record.write();
        record.reset();
    }

    void process_net_order_imbalance_indicator_message(const std::byte* pointer) {
        const auto message = NetOrderImbalanceIndicatorMessage::parse(pointer);

        record.event_type.set("Net Order Imbalance Indicator Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.paired_shares.set(message->paired_shares.get());
        record.imbalance_shares.set(message->imbalance_shares.get());
        record.imbalance_direction.set(message->imbalance_direction.get());
        record.stock.set(message->stock.get());
        record.far_price.set(message->far_price.get());
        record.near_price.set(message->near_price.get());
        record.current_reference_price.set(message->current_reference_price.get());
        record.cross_type.set(message->cross_type.get());
        record.price_variation_indicator.set(message->price_variation_indicator.get());

        record.write();
        record.reset();
    }

    void process_retail_price_improvement_indicator_message(const std::byte* pointer) {
        const auto message = RetailPriceImprovementIndicatorMessage::parse(pointer);

        record.event_type.set("Retail Price Improvement Indicator Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.interest_flag.set(message->interest_flag.get());

        record.write();
        record.reset();
    }

    void process_direct_listing_with_capital_raise_price_discovery_message(const std::byte* pointer) {
        const auto message = DirectListingWithCapitalRaisePriceDiscoveryMessage::parse(pointer);

        record.event_type.set("Direct Listing With Capital Raise Price Discovery Message");
        record.stock_locate.set(message->stock_locate.get());
        record.tracking_number.set(message->tracking_number.get());
        record.timestamp.set(message->timestamp.get());
        record.stock.set(message->stock.get());
        record.open_eligibility_status.set(message->open_eligibility_status.get());
        record.minimum_allowable_price.set(message->minimum_allowable_price.get());
        record.maximum_allowable_price.set(message->maximum_allowable_price.get());
        record.near_execution_price.set(message->near_execution_price.get());
        record.near_execution_time.set(message->near_execution_time.get());
        record.lower_price_range_collar.set(message->lower_price_range_collar.get());
        record.upper_price_range_collar.set(message->upper_price_range_collar.get());

        record.write();
        record.reset();
    }

    // packet end action
    void packet_end() {
    }
};
}
