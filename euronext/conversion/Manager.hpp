#pragma once

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/iterators/ContractEmmPropertiesGroupIterator.hpp"
#include "../protocol/iterators/EmmPatternRepGroupIterator.hpp"
#include "../protocol/iterators/InterestPaymentDateRepGroupIterator.hpp"
#include "../protocol/iterators/LongOrderUpdatesGroupIterator.hpp"
#include "../protocol/iterators/MarketStatesGroupIterator.hpp"
#include "../protocol/iterators/MarketUpdatesGroupIterator.hpp"
#include "../protocol/iterators/NewStatsGroupIterator.hpp"
#include "../protocol/iterators/NotUsedGroupIterator.hpp"
#include "../protocol/iterators/OrderUpdatesGroupIterator.hpp"
#include "../protocol/iterators/OutrightRepGroupIterator.hpp"
#include "../protocol/iterators/PackageComponentsGroupIterator.hpp"
#include "../protocol/iterators/PriceUpdatesGroupIterator.hpp"
#include "../protocol/iterators/StrategyStandingDataGroupIterator.hpp"
#include "../protocol/iterators/TimetablesGroupIterator.hpp"
#include "../protocol/iterators/OptiqMessageIterator.hpp"
#include "../protocol/groups/MarketUpdatesGroup.hpp"
#include "../protocol/groups/OrderUpdatesGroup.hpp"
#include "../protocol/groups/PriceUpdatesGroup.hpp"
#include "../protocol/groups/MarketStatesGroup.hpp"
#include "../protocol/groups/TimetablesGroup.hpp"
#include "../protocol/groups/EmmPatternRepGroup.hpp"
#include "../protocol/groups/NewStatsGroup.hpp"
#include "../protocol/groups/StrategyStandingDataGroup.hpp"
#include "../protocol/groups/ContractEmmPropertiesGroup.hpp"
#include "../protocol/groups/OutrightRepGroup.hpp"
#include "../protocol/groups/LongOrderUpdatesGroup.hpp"
#include "../protocol/groups/PackageComponentsGroup.hpp"
#include "../protocol/groups/InterestPaymentDateRepGroup.hpp"
#include "../parquet/Writer.hpp"
#include "../json/Writer.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

///////////////////////////////////////////////////////////////////////
// Euronext Sbe C++ parquet conversion manager
///////////////////////////////////////////////////////////////////////

// itch to parquet manager
struct Manager {

    ContractEmmPropertiesGroupIterator contract_emm_properties_group_iterator;
    EmmPatternRepGroupIterator emm_pattern_rep_group_iterator;
    InterestPaymentDateRepGroupIterator interest_payment_date_rep_group_iterator;
    LongOrderUpdatesGroupIterator long_order_updates_group_iterator;
    MarketStatesGroupIterator market_states_group_iterator;
    MarketUpdatesGroupIterator market_updates_group_iterator;
    NewStatsGroupIterator new_stats_group_iterator;
    NotUsedGroupIterator not_used_group_iterator;
    OrderUpdatesGroupIterator order_updates_group_iterator;
    OutrightRepGroupIterator outright_rep_group_iterator;
    PackageComponentsGroupIterator package_components_group_iterator;
    PriceUpdatesGroupIterator price_updates_group_iterator;
    StrategyStandingDataGroupIterator strategy_standing_data_group_iterator;
    TimetablesGroupIterator timetables_group_iterator;
    OptiqMessageIterator sbe;
    packet::Parser& parser;
    euronext::Writer& record;
    const conversion::Options& options;
    json::Writer json_writer;

    explicit Manager(const conversion::Options& options, packet::Parser& parser, euronext::Writer& record)
     : parser{ parser }, record{ record }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        sbe.initialize(frame.payload, frame.payload_len);

        while (sbe.next()) {
            process(sbe.message, sbe.template_id);
        }

        packet_end();
    }

    void process(const std::byte* pointer, const std::uint16_t template_id) {
        switch (template_id) {
            case 1101:
                process_start_of_day_message(pointer);
                break;

            case 1102:
                process_end_of_day_message(pointer);
                break;

            case 1103:
                process_health_status_message(pointer);
                break;

            case 1106:
                process_technical_notification_message(pointer);
                break;

            case 1001:
                process_market_update_message(pointer);
                break;

            case 1002:
                process_order_update_message(pointer);
                break;

            case 1003:
                process_price_update_message(pointer);
                break;

            case 1004:
                process_full_trade_information_message(pointer);
                break;

            case 1005:
                process_market_status_change_message(pointer);
                break;

            case 1006:
                process_timetable_message(pointer);
                break;

            case 1007:
                process_standing_data_message(pointer);
                break;

            case 1008:
                process_real_time_index_message(pointer);
                break;

            case 1009:
                process_statistics_message(pointer);
                break;

            case 1011:
                process_index_summary_message(pointer);
                break;

            case 1012:
                process_strategy_standing_data_message(pointer);
                break;

            case 1013:
                process_contract_standing_data_message(pointer);
                break;

            case 1014:
                process_outright_standing_data_message(pointer);
                break;

            case 1015:
                process_long_order_update_message(pointer);
                break;

            case 1016:
                process_lis_package_structure_message(pointer);
                break;

            case 1026:
                process_apa_quotes_message(pointer);
                break;

            case 1027:
                process_apa_standing_data_message(pointer);
                break;

            case 1028:
                process_apa_full_trade_information_message(pointer);
                break;

            case 1201:
                process_bf_instrument_reference_message(pointer);
                break;

            case 1202:
                process_bf_trade_message(pointer);
                break;

            case 1203:
                process_bfnav_message(pointer);
                break;

            case 1204:
                process_bf_instrument_suspension_message(pointer);
                break;

            case 2101:
                process_start_of_snapshot_message(pointer);
                break;

            case 2102:
                process_end_of_snapshot_message(pointer);
                break;

            default:
                break;
        }
    }

    void process_start_of_day_message(const std::byte* pointer) {
        const auto message = StartOfDayMessage::parse(pointer);

        record.event_type.set("Start Of Day Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.session_trading_day.set(message->session_trading_day.get());

        record.write();
        record.reset();
    }

    void process_end_of_day_message(const std::byte* pointer) {
        const auto message = EndOfDayMessage::parse(pointer);

        record.event_type.set("End Of Day Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.session_trading_day.set(message->session_trading_day.get());

        record.write();
        record.reset();
    }

    void process_health_status_message(const std::byte* pointer) {
        const auto message = HealthStatusMessage::parse(pointer);

        record.event_type.set("Health Status Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.event_time.set(message->event_time.get());

        record.write();
        record.reset();
    }

    void process_technical_notification_message(const std::byte* pointer) {
        const auto message = TechnicalNotificationMessage::parse(pointer);

        record.event_type.set("Technical Notification Message");
        record.md_seq_num_optional.set(message->md_seq_num_optional.get());
        record.technical_notification_type.set(message->technical_notification_type.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.retransmission_start_time.set(message->retransmission_start_time.get());
        record.retransmission_end_time.set(message->retransmission_end_time.get());
        record.symbol_index_optional.set(message->symbol_index_optional.get());

        record.write();
        record.reset();
    }

    void process_market_update_message(const std::byte* pointer) {
        const auto message = MarketUpdateMessage::parse(pointer);

        record.event_type.set("Market Update Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());

        // repeating group: Market Updates Group (serialized as JSON)
        json_writer.start_array();
        market_updates_group_iterator.initialize(pointer + sizeof(MarketUpdateMessage));
        while (market_updates_group_iterator.next()) {
            const auto* entry = MarketUpdatesGroup::parse(market_updates_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Update Type", entry->update_type.get());
            json_writer.field("Symbol Index", entry->symbol_index.get());
            json_writer.field("Number Of Orders", entry->number_of_orders.get());
            json_writer.field("Price", entry->price.get());
            json_writer.field("Quantity Optional", entry->quantity_optional.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.market_updates_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_order_update_message(const std::byte* pointer) {
        const auto message = OrderUpdateMessage::parse(pointer);

        record.event_type.set("Order Update Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());

        // repeating group: Order Updates Group (serialized as JSON)
        json_writer.start_array();
        order_updates_group_iterator.initialize(pointer + sizeof(OrderUpdateMessage));
        while (order_updates_group_iterator.next()) {
            const auto* entry = OrderUpdatesGroup::parse(order_updates_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Symbol Index", entry->symbol_index.get());
            json_writer.field("Action Type", entry->action_type.get());
            json_writer.field("Order Priority", entry->order_priority.get());
            json_writer.field("Previous Priority", entry->previous_priority.get());
            json_writer.field("Order Type", entry->order_type.get());
            json_writer.field("Order Px", entry->order_px.get());
            json_writer.field("Order Side", entry->order_side.get());
            json_writer.field("Order Quantity", entry->order_quantity.get());
            json_writer.field("Peg Offset", entry->peg_offset.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.order_updates_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_price_update_message(const std::byte* pointer) {
        const auto message = PriceUpdateMessage::parse(pointer);

        record.event_type.set("Price Update Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());

        // repeating group: Price Updates Group (serialized as JSON)
        json_writer.start_array();
        price_updates_group_iterator.initialize(pointer + sizeof(PriceUpdateMessage));
        while (price_updates_group_iterator.next()) {
            const auto* entry = PriceUpdatesGroup::parse(price_updates_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Price Type", entry->price_type.get());
            json_writer.field("Symbol Index", entry->symbol_index.get());
            json_writer.field("Price", entry->price.get());
            json_writer.field("Quantity Optional", entry->quantity_optional.get());
            json_writer.field("Imbalance Qty", entry->imbalance_qty.get());
            json_writer.field("Imbalance Qty Side", entry->imbalance_qty_side.get());
            json_writer.field("Price Qualifier", entry->price_qualifier.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.price_updates_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_full_trade_information_message(const std::byte* pointer) {
        const auto message = FullTradeInformationMessage::parse(pointer);

        record.event_type.set("Full Trade Information Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());
        record.symbol_index_optional.set(message->symbol_index_optional.get());
        record.trading_date_time.set(message->trading_date_time.get());
        record.publication_date_time.set(message->publication_date_time.get());
        record.trade_type.set(message->trade_type.get());
        record.mifid_instrument_id_type_optional.set(message->mifid_instrument_id_type_optional.get());
        record.mifid_instrument_id_optional.set(message->mifid_instrument_id_optional.get());
        record.mifid_execution_id.set(message->mifid_execution_id.get());
        record.mifid_price_optional.set(message->mifid_price_optional.get());
        record.mifid_quantity.set(message->mifid_quantity.get());
        record.mifid_price_notation.set(message->mifid_price_notation.get());
        record.mifid_currency.set(message->mifid_currency.get());
        record.mifid_qty_in_msrmt_unit_notation.set(message->mifid_qty_in_msrmt_unit_notation.get());
        record.mifid_quantity_measurement_unit.set(message->mifid_quantity_measurement_unit.get());
        record.mifid_notional_amount.set(message->mifid_notional_amount.get());
        record.notional_currency.set(message->notional_currency.get());
        record.mifid_clearing_flag.set(message->mifid_clearing_flag.get());
        record.mmt_market_mechanism.set(message->mmt_market_mechanism.get());
        record.mmt_trading_mode.set(message->mmt_trading_mode.get());
        record.mmt_transaction_category.set(message->mmt_transaction_category.get());
        record.mmt_negotiation_indicator.set(message->mmt_negotiation_indicator.get());
        record.mmt_agency_cross_trade_indicator.set(message->mmt_agency_cross_trade_indicator.get());
        record.mmt_modification_indicator_char_4_optional.set(message->mmt_modification_indicator_char_4_optional.get());
        record.mmt_benchmark_indicator.set(message->mmt_benchmark_indicator.get());
        record.mmt_special_dividend_indicator.set(message->mmt_special_dividend_indicator.get());
        record.mmt_off_book_automated_indicator.set(message->mmt_off_book_automated_indicator.get());
        record.mmt_contributionto_price.set(message->mmt_contributionto_price.get());
        record.mmt_algorithmic_indicator.set(message->mmt_algorithmic_indicator.get());
        record.mmt_publication_mode.set(message->mmt_publication_mode.get());
        record.mmt_post_trade_deferral.set(message->mmt_post_trade_deferral.get());
        record.mmt_duplicative_indicator.set(message->mmt_duplicative_indicator.get());
        record.transaction_type.set(message->transaction_type.get());
        record.effective_date_indicator.set(message->effective_date_indicator.get());
        record.block_trade_code.set(message->block_trade_code.get());
        record.trade_reference.set(message->trade_reference.get());
        record.original_report_timestamp.set(message->original_report_timestamp.get());
        record.transparency_indicator.set(message->transparency_indicator.get());
        record.currency_coefficient.set(message->currency_coefficient.get());
        record.price_multiplier.set(message->price_multiplier.get());
        record.price_multiplier_decimals.set(message->price_multiplier_decimals.get());
        record.venue.set(message->venue.get());
        record.start_time_vwap.set(message->start_time_vwap.get());
        record.end_time_vwap.set(message->end_time_vwap.get());
        record.mifid_emission_allowance_type.set(message->mifid_emission_allowance_type.get());
        record.market_of_reference_mic.set(message->market_of_reference_mic.get());
        record.evaluated_price.set(message->evaluated_price.get());
        record.message_price_notation.set(message->message_price_notation.get());
        record.settlement_date.set(message->settlement_date.get());
        record.repo_settlement_date.set(message->repo_settlement_date.get());
        record.trade_unique_identifier.set(message->trade_unique_identifier.get());

        // repeating group: Not Used Group (serialized as JSON)
        json_writer.start_array();
        not_used_group_iterator.initialize(pointer + sizeof(FullTradeInformationMessage));
        while (not_used_group_iterator.next()) {
            json_writer.start_element();
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.not_used_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_market_status_change_message(const std::byte* pointer) {
        const auto message = MarketStatusChangeMessage::parse(pointer);

        record.event_type.set("Market Status Change Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());

        // repeating group: Market States Group (serialized as JSON)
        json_writer.start_array();
        market_states_group_iterator.initialize(pointer + sizeof(MarketStatusChangeMessage));
        while (market_states_group_iterator.next()) {
            const auto* entry = MarketStatesGroup::parse(market_states_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Change Type", entry->change_type.get());
            json_writer.field("Symbol Index", entry->symbol_index.get());
            json_writer.field("Event Time", entry->event_time.get());
            json_writer.field("Book State", entry->book_state.get());
            json_writer.field("Status Reason", entry->status_reason.get());
            json_writer.field("Trading Period Optional", entry->trading_period_optional.get());
            json_writer.field("Trading Side", entry->trading_side.get());
            json_writer.field("Price Limits", entry->price_limits.get());
            json_writer.field("Quote Spread Multiplier", entry->quote_spread_multiplier.get());
            json_writer.field("Order Entry Qualifier", entry->order_entry_qualifier.get());
            json_writer.field("Session", entry->session.get());
            json_writer.field("Scheduled Event", entry->scheduled_event.get());
            json_writer.field("Scheduled Event Time", entry->scheduled_event_time.get());
            json_writer.field("Instrument State", entry->instrument_state.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.market_states_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_timetable_message(const std::byte* pointer) {
        const auto message = TimetableMessage::parse(pointer);

        record.event_type.set("Timetable Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm_optional.set(message->emm_optional.get());
        record.pattern_id.set(message->pattern_id.get());
        record.symbol_index_optional.set(message->symbol_index_optional.get());

        // repeating group: Timetables Group (serialized as JSON)
        json_writer.start_array();
        timetables_group_iterator.initialize(pointer + sizeof(TimetableMessage));
        while (timetables_group_iterator.next()) {
            const auto* entry = TimetablesGroup::parse(timetables_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Phase Time", entry->phase_time.get());
            json_writer.field("Phase Id", entry->phase_id.get());
            json_writer.field("Trading Period", entry->trading_period.get());
            json_writer.field("Order Entry Qualifier", entry->order_entry_qualifier.get());
            json_writer.field("Session", entry->session.get());
            json_writer.field("Scheduled Event", entry->scheduled_event.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.timetables_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_standing_data_message(const std::byte* pointer) {
        const auto message = StandingDataMessage::parse(pointer);

        record.event_type.set("Standing Data Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());
        record.optiq_segment.set(message->optiq_segment.get());
        record.partition_id.set(message->partition_id.get());
        record.full_instrument_name.set(message->full_instrument_name.get());
        record.instrument_name.set(message->instrument_name.get());
        record.instrument_trading_code.set(message->instrument_trading_code.get());
        record.instrument_group_code.set(message->instrument_group_code.get());
        record.isin_code.set(message->isin_code.get());
        record.price_decimals.set(message->price_decimals.get());
        record.quantity_decimals.set(message->quantity_decimals.get());
        record.amount_decimals.set(message->amount_decimals.get());
        record.ratio_decimals.set(message->ratio_decimals.get());
        record.cfi.set(message->cfi.get());
        record.instrument_event_date.set(message->instrument_event_date.get());
        record.strike_price.set(message->strike_price.get());
        record.dark_eligibility.set(message->dark_eligibility.get());
        record.dark_lis_threshold.set(message->dark_lis_threshold.get());
        record.dark_min_quantity.set(message->dark_min_quantity.get());
        record.date_of_last_trade.set(message->date_of_last_trade.get());
        record.depositary_list.set(message->depositary_list.get());
        record.main_depositary.set(message->main_depositary.get());
        record.first_settlement_date.set(message->first_settlement_date.get());
        record.guarantee_indicator.set(message->guarantee_indicator.get());
        record.icb.set(message->icb.get());
        record.issuing_country.set(message->issuing_country.get());
        record.last_adjusted_closing_price.set(message->last_adjusted_closing_price.get());
        record.lot_size_optional.set(message->lot_size_optional.get());
        record.maturity_date_optional.set(message->maturity_date_optional.get());
        record.maximum_decimals_in_quantity.set(message->maximum_decimals_in_quantity.get());
        record.mic.set(message->mic.get());
        record.mic_list.set(message->mic_list.get());
        record.country_of_exchange_optional.set(message->country_of_exchange_optional.get());
        record.mnemonic.set(message->mnemonic.get());
        record.underlying_mic.set(message->underlying_mic.get());
        record.underlying_isin_code.set(message->underlying_isin_code.get());
        record.trading_currency_optional.set(message->trading_currency_optional.get());
        record.currency_coefficient.set(message->currency_coefficient.get());
        record.trading_currency_indicator.set(message->trading_currency_indicator.get());
        record.strike_currency_indicator.set(message->strike_currency_indicator.get());
        record.number_instrument_circulating.set(message->number_instrument_circulating.get());
        record.par_value.set(message->par_value.get());
        record.quantity_notation.set(message->quantity_notation.get());
        record.inst_unit_exp.set(message->inst_unit_exp.get());
        record.settlement_delay.set(message->settlement_delay.get());
        record.strike_currency.set(message->strike_currency.get());
        record.tax_code.set(message->tax_code.get());
        record.type_of_corporate_event.set(message->type_of_corporate_event.get());
        record.type_of_market_admission.set(message->type_of_market_admission.get());
        record.repo_indicator.set(message->repo_indicator.get());
        record.issue_price.set(message->issue_price.get());
        record.nominal_currency.set(message->nominal_currency.get());
        record.issue_price_decimals.set(message->issue_price_decimals.get());
        record.strike_price_decimals.set(message->strike_price_decimals.get());
        record.liquid_instrument_indicator.set(message->liquid_instrument_indicator.get());
        record.market_of_reference_mic.set(message->market_of_reference_mic.get());
        record.icb_code.set(message->icb_code.get());
        record.threshold_lis_post_trade_60mn.set(message->threshold_lis_post_trade_60mn.get());
        record.threshold_lis_post_trade_120mn.set(message->threshold_lis_post_trade_120mn.get());
        record.threshold_lis_post_trade_eod.set(message->threshold_lis_post_trade_eod.get());
        record.long_mnemonic.set(message->long_mnemonic.get());
        record.max_order_amount_call.set(message->max_order_amount_call.get());
        record.max_order_amount_continuous.set(message->max_order_amount_continuous.get());
        record.max_order_quantity_call.set(message->max_order_quantity_call.get());
        record.max_order_quantity_continuous.set(message->max_order_quantity_continuous.get());
        record.pool_factor.set(message->pool_factor.get());

        // repeating group: Emm Pattern Rep Group (serialized as JSON)
        json_writer.start_array();
        emm_pattern_rep_group_iterator.initialize(pointer + sizeof(StandingDataMessage));
        while (emm_pattern_rep_group_iterator.next()) {
            const auto* entry = EmmPatternRepGroup::parse(emm_pattern_rep_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Emm", entry->emm.get());
            json_writer.field("Pattern Id", entry->pattern_id.get());
            json_writer.field("Tick Size Index Id", entry->tick_size_index_id.get());
            json_writer.field("Market Model", entry->market_model.get());
            json_writer.field("Lot Size Optional", entry->lot_size_optional.get());
            json_writer.field("Inst Unit Exp", entry->inst_unit_exp.get());
            json_writer.field("Anonymous", entry->anonymous.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.emm_pattern_rep_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_real_time_index_message(const std::byte* pointer) {
        const auto message = RealTimeIndexMessage::parse(pointer);

        record.event_type.set("Real Time Index Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());
        record.symbol_index.set(message->symbol_index.get());
        record.index_level.set(message->index_level.get());
        record.pctg_of_capitalization.set(message->pctg_of_capitalization.get());
        record.prct_varfrom_prev_close.set(message->prct_varfrom_prev_close.get());
        record.num_traded_instruments.set(message->num_traded_instruments.get());
        record.index_level_type.set(message->index_level_type.get());
        record.index_price_code.set(message->index_price_code.get());

        record.write();
        record.reset();
    }

    void process_statistics_message(const std::byte* pointer) {
        const auto message = StatisticsMessage::parse(pointer);

        record.event_type.set("Statistics Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());

        // repeating group: New Stats Group (serialized as JSON)
        json_writer.start_array();
        new_stats_group_iterator.initialize(pointer + sizeof(StatisticsMessage));
        while (new_stats_group_iterator.next()) {
            const auto* entry = NewStatsGroup::parse(new_stats_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Stats Update Type", entry->stats_update_type.get());
            json_writer.field("Stats Update Value", entry->stats_update_value.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.new_stats_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_index_summary_message(const std::byte* pointer) {
        const auto message = IndexSummaryMessage::parse(pointer);

        record.event_type.set("Index Summary Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());
        record.symbol_index.set(message->symbol_index.get());
        record.opening_level.set(message->opening_level.get());
        record.opening_time.set(message->opening_time.get());
        record.confirmed_reference_level.set(message->confirmed_reference_level.get());
        record.confirmed_reference_time.set(message->confirmed_reference_time.get());
        record.closing_reference_level.set(message->closing_reference_level.get());
        record.closing_reference_time.set(message->closing_reference_time.get());
        record.prct_varfrom_prev_close.set(message->prct_varfrom_prev_close.get());
        record.high_level.set(message->high_level.get());
        record.high_time.set(message->high_time.get());
        record.low_level.set(message->low_level.get());
        record.low_time.set(message->low_time.get());
        record.liquidation_level.set(message->liquidation_level.get());
        record.liquidation_time.set(message->liquidation_time.get());

        record.write();
        record.reset();
    }

    void process_strategy_standing_data_message(const std::byte* pointer) {
        const auto message = StrategyStandingDataMessage::parse(pointer);

        record.event_type.set("Strategy Standing Data Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.symbol_index.set(message->symbol_index.get());
        record.derivatives_instrument_trading_code.set(message->derivatives_instrument_trading_code.get());
        record.exchange_code.set(message->exchange_code.get());
        record.maturity_date.set(message->maturity_date.get());
        record.strategy_code.set(message->strategy_code.get());
        record.contract_symbol_index.set(message->contract_symbol_index.get());
        record.cfi_optional.set(message->cfi_optional.get());

        // repeating group: Strategy Standing Data Group (serialized as JSON)
        json_writer.start_array();
        strategy_standing_data_group_iterator.initialize(pointer + sizeof(StrategyStandingDataMessage));
        while (strategy_standing_data_group_iterator.next()) {
            const auto* entry = StrategyStandingDataGroup::parse(strategy_standing_data_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Leg Symbol Index", entry->leg_symbol_index.get());
            json_writer.field("Leg Price", entry->leg_price.get());
            json_writer.field("Leg Ratio", entry->leg_ratio.get());
            json_writer.field("Leg Buy Sell", entry->leg_buy_sell.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.strategy_standing_data_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_contract_standing_data_message(const std::byte* pointer) {
        const auto message = ContractStandingDataMessage::parse(pointer);

        record.event_type.set("Contract Standing Data Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());
        record.optiq_segment.set(message->optiq_segment.get());
        record.partition_id.set(message->partition_id.get());
        record.contract_event_date.set(message->contract_event_date.get());
        record.exchange_code.set(message->exchange_code.get());
        record.exer_style.set(message->exer_style.get());
        record.contract_name.set(message->contract_name.get());
        record.contract_type.set(message->contract_type.get());
        record.underlying_type.set(message->underlying_type.get());
        record.price_decimals_optional.set(message->price_decimals_optional.get());
        record.quantity_decimals.set(message->quantity_decimals.get());
        record.amount_decimals.set(message->amount_decimals.get());
        record.ratio_decimals_optional.set(message->ratio_decimals_optional.get());
        record.main_depositary.set(message->main_depositary.get());
        record.mic.set(message->mic.get());
        record.country_of_exchange.set(message->country_of_exchange.get());
        record.product_code.set(message->product_code.get());
        record.underlying_mic.set(message->underlying_mic.get());
        record.underlying_isin_code.set(message->underlying_isin_code.get());
        record.underlying_expiry.set(message->underlying_expiry.get());
        record.settlement_method.set(message->settlement_method.get());
        record.trading_currency.set(message->trading_currency.get());
        record.strike_price_decimals_ratio.set(message->strike_price_decimals_ratio.get());
        record.contract_trading_type.set(message->contract_trading_type.get());
        record.inst_unit_exp.set(message->inst_unit_exp.get());
        record.underlying_subtype.set(message->underlying_subtype.get());
        record.mother_stock_isin.set(message->mother_stock_isin.get());
        record.settlement_tick_size.set(message->settlement_tick_size.get());
        record.edsp_tick_size.set(message->edsp_tick_size.get());
        record.underlying_symbol_index.set(message->underlying_symbol_index.get());
        record.trading_policy.set(message->trading_policy.get());
        record.reference_spread_table_id.set(message->reference_spread_table_id.get());
        record.derivatives_market_model.set(message->derivatives_market_model.get());
        record.trading_unit.set(message->trading_unit.get());
        record.reference_price_origin_in_opening_call.set(message->reference_price_origin_in_opening_call.get());
        record.reference_price_origin_in_continuous.set(message->reference_price_origin_in_continuous.get());
        record.reference_price_origin_in_trading_interruption.set(message->reference_price_origin_in_trading_interruption.get());
        record.collar_expansion_factor.set(message->collar_expansion_factor.get());
        record.mifidii_liquid_flag.set(message->mifidii_liquid_flag.get());
        record.pricing_algorithm.set(message->pricing_algorithm.get());

        // repeating group: Contract Emm Properties Group (serialized as JSON)
        json_writer.start_array();
        contract_emm_properties_group_iterator.initialize(pointer + sizeof(ContractStandingDataMessage));
        while (contract_emm_properties_group_iterator.next()) {
            const auto* entry = ContractEmmPropertiesGroup::parse(contract_emm_properties_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Emm Optional", entry->emm_optional.get());
            json_writer.field("Tick Size Index Id", entry->tick_size_index_id.get());
            json_writer.field("Pattern Id", entry->pattern_id.get());
            json_writer.field("Lot Size Optional", entry->lot_size_optional.get());
            json_writer.field("Dynamic Collar Logic", entry->dynamic_collar_logic.get());
            json_writer.field("Collar Max Unhalt Nb", entry->collar_max_unhalt_nb.get());
            json_writer.field("Collar Unhalt Delay", entry->collar_unhalt_delay.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.contract_emm_properties_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_outright_standing_data_message(const std::byte* pointer) {
        const auto message = OutrightStandingDataMessage::parse(pointer);

        record.event_type.set("Outright Standing Data Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());
        record.contract_symbol_index.set(message->contract_symbol_index.get());
        record.instrument_event_date.set(message->instrument_event_date.get());
        record.isin_code.set(message->isin_code.get());
        record.cfi_optional.set(message->cfi_optional.get());
        record.maturity_date.set(message->maturity_date.get());
        record.lot_size.set(message->lot_size.get());
        record.strike_price.set(message->strike_price.get());
        record.last_trading_date.set(message->last_trading_date.get());
        record.days_to_expiry.set(message->days_to_expiry.get());
        record.derivatives_instrument_trading_code_optional.set(message->derivatives_instrument_trading_code_optional.get());
        record.derivatives_instrument_type.set(message->derivatives_instrument_type.get());
        record.expiry_cycle_type.set(message->expiry_cycle_type.get());
        record.underlying_derivatives_instrument_trading_code.set(message->underlying_derivatives_instrument_trading_code.get());
        record.underlying_symbol_index.set(message->underlying_symbol_index.get());
        record.trading_unit.set(message->trading_unit.get());

        // repeating group: Outright Rep Group (serialized as JSON)
        json_writer.start_array();
        outright_rep_group_iterator.initialize(pointer + sizeof(OutrightStandingDataMessage));
        while (outright_rep_group_iterator.next()) {
            const auto* entry = OutrightRepGroup::parse(outright_rep_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Emm", entry->emm.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.outright_rep_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_long_order_update_message(const std::byte* pointer) {
        const auto message = LongOrderUpdateMessage::parse(pointer);

        record.event_type.set("Long Order Update Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());

        // repeating group: Long Order Updates Group (serialized as JSON)
        json_writer.start_array();
        long_order_updates_group_iterator.initialize(pointer + sizeof(LongOrderUpdateMessage));
        while (long_order_updates_group_iterator.next()) {
            const auto* entry = LongOrderUpdatesGroup::parse(long_order_updates_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Symbol Index", entry->symbol_index.get());
            json_writer.field("Action Type", entry->action_type.get());
            json_writer.field("Order Priority", entry->order_priority.get());
            json_writer.field("Previous Priority", entry->previous_priority.get());
            json_writer.field("Order Type", entry->order_type.get());
            json_writer.field("Order Px", entry->order_px.get());
            json_writer.field("Order Side", entry->order_side.get());
            json_writer.field("Order Quantity", entry->order_quantity.get());
            json_writer.field("Peg Offset", entry->peg_offset.get());
            json_writer.field("Firm Id", entry->firm_id.get());
            json_writer.field("Account Type", entry->account_type.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.long_order_updates_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_lis_package_structure_message(const std::byte* pointer) {
        const auto message = LisPackageStructureMessage::parse(pointer);

        record.event_type.set("Lis Package Structure Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());
        record.contract_symbol_index.set(message->contract_symbol_index.get());
        record.mifid_execution_id.set(message->mifid_execution_id.get());
        record.strategy_code.set(message->strategy_code.get());

        // repeating group: Package Components Group (serialized as JSON)
        json_writer.start_array();
        package_components_group_iterator.initialize(pointer + sizeof(LisPackageStructureMessage));
        while (package_components_group_iterator.next()) {
            const auto* entry = PackageComponentsGroup::parse(package_components_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Leg Symbol Index", entry->leg_symbol_index.get());
            json_writer.field("Leg Ratio", entry->leg_ratio.get());
            json_writer.field("Leg Last Px", entry->leg_last_px.get());
            json_writer.field("Leg Last Qty", entry->leg_last_qty.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.package_components_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_apa_quotes_message(const std::byte* pointer) {
        const auto message = ApaQuotesMessage::parse(pointer);

        record.event_type.set("Apa Quotes Message");
        record.md_seq_num_optional.set(message->md_seq_num_optional.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.mifid_instrument_id_type.set(message->mifid_instrument_id_type.get());
        record.mifid_instrument_id.set(message->mifid_instrument_id.get());
        record.mic.set(message->mic.get());
        record.currency.set(message->currency.get());
        record.lei_code.set(message->lei_code.get());
        record.event_time.set(message->event_time.get());
        record.quote_update_type.set(message->quote_update_type.get());
        record.mifid_price.set(message->mifid_price.get());
        record.mifid_quantity.set(message->mifid_quantity.get());
        record.apa_origin.set(message->apa_origin.get());

        record.write();
        record.reset();
    }

    void process_apa_standing_data_message(const std::byte* pointer) {
        const auto message = ApaStandingDataMessage::parse(pointer);

        record.event_type.set("Apa Standing Data Message");
        record.md_seq_num_optional.set(message->md_seq_num_optional.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.mifid_instrument_id_type.set(message->mifid_instrument_id_type.get());
        record.mifid_instrument_id.set(message->mifid_instrument_id.get());
        record.full_instrument_name.set(message->full_instrument_name.get());
        record.cfi_optional.set(message->cfi_optional.get());
        record.notional_currency.set(message->notional_currency.get());
        record.second_notional_currency.set(message->second_notional_currency.get());
        record.price_multiplier.set(message->price_multiplier.get());
        record.price_multiplier_decimals.set(message->price_multiplier_decimals.get());
        record.underlying_isin_code.set(message->underlying_isin_code.get());
        record.underlying_index_name.set(message->underlying_index_name.get());
        record.underlying_index_term.set(message->underlying_index_term.get());
        record.option_type.set(message->option_type.get());
        record.strike_price.set(message->strike_price.get());
        record.strike_price_decimals.set(message->strike_price_decimals.get());
        record.exer_style.set(message->exer_style.get());
        record.maturity_date_optional.set(message->maturity_date_optional.get());
        record.expiry_date.set(message->expiry_date.get());
        record.settlement_method.set(message->settlement_method.get());

        record.write();
        record.reset();
    }

    void process_apa_full_trade_information_message(const std::byte* pointer) {
        const auto message = ApaFullTradeInformationMessage::parse(pointer);

        record.event_type.set("Apa Full Trade Information Message");
        record.md_seq_num.set(message->md_seq_num.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.emm.set(message->emm.get());
        record.event_time.set(message->event_time.get());
        record.trading_date_time.set(message->trading_date_time.get());
        record.publication_date_time.set(message->publication_date_time.get());
        record.trade_type.set(message->trade_type.get());
        record.mifid_instrument_id_type_optional.set(message->mifid_instrument_id_type_optional.get());
        record.mifid_instrument_id_optional.set(message->mifid_instrument_id_optional.get());
        record.mifid_transaction_id.set(message->mifid_transaction_id.get());
        record.mifid_price_optional.set(message->mifid_price_optional.get());
        record.mifid_quantity.set(message->mifid_quantity.get());
        record.mifid_price_notation.set(message->mifid_price_notation.get());
        record.mifid_currency.set(message->mifid_currency.get());
        record.mifid_qty_in_msrmt_unit_notation.set(message->mifid_qty_in_msrmt_unit_notation.get());
        record.mifid_quantity_measurement_unit.set(message->mifid_quantity_measurement_unit.get());
        record.mifid_notional_amount.set(message->mifid_notional_amount.get());
        record.notional_currency.set(message->notional_currency.get());
        record.mifid_clearing_flag.set(message->mifid_clearing_flag.get());
        record.efficient_mmt_market_mechanism.set(message->efficient_mmt_market_mechanism.get());
        record.efficient_mmt_trading_mode.set(message->efficient_mmt_trading_mode.get());
        record.efficient_mmt_transaction_category.set(message->efficient_mmt_transaction_category.get());
        record.efficient_mmt_negotiation_indicator.set(message->efficient_mmt_negotiation_indicator.get());
        record.efficient_mmt_agency_cross_trade_indicator.set(message->efficient_mmt_agency_cross_trade_indicator.get());
        record.efficient_mmt_modification_indicator.set(message->efficient_mmt_modification_indicator.get());
        record.efficient_mmt_benchmark_indicator.set(message->efficient_mmt_benchmark_indicator.get());
        record.efficient_mmt_special_dividend_indicator.set(message->efficient_mmt_special_dividend_indicator.get());
        record.efficient_mmt_off_book_automated_indicator.set(message->efficient_mmt_off_book_automated_indicator.get());
        record.efficient_mmt_contributionto_price.set(message->efficient_mmt_contributionto_price.get());
        record.efficient_mmt_algorithmic_indicator.set(message->efficient_mmt_algorithmic_indicator.get());
        record.efficient_mmt_publication_mode.set(message->efficient_mmt_publication_mode.get());
        record.efficient_mmt_post_trade_deferral.set(message->efficient_mmt_post_trade_deferral.get());
        record.efficient_mmt_duplicative_indicator.set(message->efficient_mmt_duplicative_indicator.get());
        record.trade_reference.set(message->trade_reference.get());
        record.original_report_timestamp.set(message->original_report_timestamp.get());
        record.price_multiplier.set(message->price_multiplier.get());
        record.price_multiplier_decimals.set(message->price_multiplier_decimals.get());
        record.venue.set(message->venue.get());
        record.mifid_emission_allowance_type.set(message->mifid_emission_allowance_type.get());
        record.long_trade_reference.set(message->long_trade_reference.get());
        record.apa_origin.set(message->apa_origin.get());
        record.trade_unique_identifier.set(message->trade_unique_identifier.get());

        record.write();
        record.reset();
    }

    void process_bf_instrument_reference_message(const std::byte* pointer) {
        const auto message = BfInstrumentReferenceMessage::parse(pointer);

        record.event_type.set("Bf Instrument Reference Message");
        record.md_seq_num_optional.set(message->md_seq_num_optional.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());
        record.optiq_segment.set(message->optiq_segment.get());
        record.isin_code_optional.set(message->isin_code_optional.get());
        record.sedol_code.set(message->sedol_code.get());
        record.long_issuer_name.set(message->long_issuer_name.get());
        record.long_instrument_name.set(message->long_instrument_name.get());
        record.currency_optional.set(message->currency_optional.get());
        record.date_of_initial_listing.set(message->date_of_initial_listing.get());
        record.share_amount_in_issue.set(message->share_amount_in_issue.get());
        record.opened_closed_fund.set(message->opened_closed_fund.get());
        record.last_nav_price.set(message->last_nav_price.get());
        record.gross_of_cdsc_indicator.set(message->gross_of_cdsc_indicator.get());
        record.coupon.set(message->coupon.get());
        record.maturity_date_optional.set(message->maturity_date_optional.get());
        record.closing_price.set(message->closing_price.get());
        record.mic_optional.set(message->mic_optional.get());
        record.gross_dividend_payable_per_unit.set(message->gross_dividend_payable_per_unit.get());
        record.dividend_currency.set(message->dividend_currency.get());
        record.dividend_record_date.set(message->dividend_record_date.get());
        record.dividend_rate.set(message->dividend_rate.get());
        record.ex_dividend_date.set(message->ex_dividend_date.get());
        record.dividend_payment_date.set(message->dividend_payment_date.get());
        record.tax_description_attaching_to_a_dividend.set(message->tax_description_attaching_to_a_dividend.get());
        record.next_meeting.set(message->next_meeting.get());
        record.gross_dividend_in_euros.set(message->gross_dividend_in_euros.get());
        record.issue_date.set(message->issue_date.get());
        record.issuing_country.set(message->issuing_country.get());
        record.cfi_optional.set(message->cfi_optional.get());
        record.payment_frequency.set(message->payment_frequency.get());
        record.minimum_amount.set(message->minimum_amount.get());
        record.instrument_category.set(message->instrument_category.get());
        record.security_condition.set(message->security_condition.get());
        record.mifid_price_notation.set(message->mifid_price_notation.get());
        record.price_index_level_decimals.set(message->price_index_level_decimals.get());
        record.quantity_decimals.set(message->quantity_decimals.get());
        record.amount_decimals.set(message->amount_decimals.get());
        record.ratio_multiplier_decimals.set(message->ratio_multiplier_decimals.get());

        // repeating group: Interest Payment Date Rep Group (serialized as JSON)
        json_writer.start_array();
        interest_payment_date_rep_group_iterator.initialize(pointer + sizeof(BfInstrumentReferenceMessage));
        while (interest_payment_date_rep_group_iterator.next()) {
            const auto* entry = InterestPaymentDateRepGroup::parse(interest_payment_date_rep_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Interest Payment Date", entry->interest_payment_date.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.interest_payment_date_rep_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_bf_trade_message(const std::byte* pointer) {
        const auto message = BfTradeMessage::parse(pointer);

        record.event_type.set("Bf Trade Message");
        record.md_seq_num_optional.set(message->md_seq_num_optional.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());
        record.mifid_transaction_id.set(message->mifid_transaction_id.get());
        record.event_time.set(message->event_time.get());
        record.bid_offer_date_time.set(message->bid_offer_date_time.get());
        record.mmt_modification_indicator.set(message->mmt_modification_indicator.get());
        record.price.set(message->price.get());
        record.bid_price.set(message->bid_price.get());
        record.offer_price.set(message->offer_price.get());
        record.quantity.set(message->quantity.get());
        record.mmt_agency_cross_trade_indicator.set(message->mmt_agency_cross_trade_indicator.get());
        record.mmt_benchmark_indicator.set(message->mmt_benchmark_indicator.get());
        record.mmt_special_dividend_indicator.set(message->mmt_special_dividend_indicator.get());
        record.mmt_trading_mode.set(message->mmt_trading_mode.get());
        record.mifid_price_notation.set(message->mifid_price_notation.get());
        record.quantity_notation.set(message->quantity_notation.get());
        record.notional_amount_traded.set(message->notional_amount_traded.get());
        record.trading_currency_optional.set(message->trading_currency_optional.get());

        record.write();
        record.reset();
    }

    void process_bfnav_message(const std::byte* pointer) {
        const auto message = BfnavMessage::parse(pointer);

        record.event_type.set("Bfnav Message");
        record.md_seq_num_optional.set(message->md_seq_num_optional.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());
        record.bid_offer_date_time.set(message->bid_offer_date_time.get());
        record.mifid_transaction_id.set(message->mifid_transaction_id.get());
        record.mmt_modification_indicator.set(message->mmt_modification_indicator.get());
        record.nav_price.set(message->nav_price.get());
        record.event_time_optional.set(message->event_time_optional.get());
        record.nav_bid_price.set(message->nav_bid_price.get());
        record.nav_offer_price.set(message->nav_offer_price.get());

        record.write();
        record.reset();
    }

    void process_bf_instrument_suspension_message(const std::byte* pointer) {
        const auto message = BfInstrumentSuspensionMessage::parse(pointer);

        record.event_type.set("Bf Instrument Suspension Message");
        record.md_seq_num_optional.set(message->md_seq_num_optional.get());
        record.rebroadcast_indicator.set(message->rebroadcast_indicator.get());
        record.symbol_index.set(message->symbol_index.get());
        record.event_time.set(message->event_time.get());
        record.security_condition.set(message->security_condition.get());

        record.write();
        record.reset();
    }

    void process_start_of_snapshot_message(const std::byte* pointer) {
        const auto message = StartOfSnapshotMessage::parse(pointer);

        record.event_type.set("Start Of Snapshot Message");
        record.last_md_seq_num.set(message->last_md_seq_num.get());
        record.snapshot_time.set(message->snapshot_time.get());

        record.write();
        record.reset();
    }

    void process_end_of_snapshot_message(const std::byte* pointer) {
        const auto message = EndOfSnapshotMessage::parse(pointer);

        record.event_type.set("End Of Snapshot Message");
        record.last_md_seq_num.set(message->last_md_seq_num.get());
        record.snapshot_time.set(message->snapshot_time.get());

        record.write();
        record.reset();
    }

    // packet end action
    void packet_end() {
    }
};
}
