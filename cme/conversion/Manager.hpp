#pragma once

#include "Settings.hpp"
#include "../packet/Parser.hpp"
#include "../protocol/iterators/ChannelResetGroupIterator.hpp"
#include "../protocol/iterators/IncrementalRefreshVolumeGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshBook32NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshBook32NoOrderIDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshDailyStatistics33NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshLimitsBanding34NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshOrderBook43NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshSessionStatistics35NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshTrade36NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshTradeSummary42NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionFuture27NoEventsGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionFuture27NoInstAttribGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionFuture27NoLotTypeRulesGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionFuture27NoMDFeedTypesGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionOption41NoEventsGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionOption41NoInstAttribGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionOption41NoLotTypeRulesGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionOption41NoMDFeedTypesGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionOption41NoRelatedInstrumentsGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionOption41NoUnderlyingsGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionSpread29NoEventsGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionSpread29NoInstAttribGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionSpread29NoLegsGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionSpread29NoLotTypeRulesGroupIterator.hpp"
#include "../protocol/iterators/MDInstrumentDefinitionSpread29NoMDFeedTypesGroupIterator.hpp"
#include "../protocol/iterators/RelatedSymGroupIterator.hpp"
#include "../protocol/iterators/SnapshotFullRefresh38NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/SnapshotFullRefreshOrderBook44NoMDEntriesGroupIterator.hpp"
#include "../protocol/iterators/MessageIterator.hpp"
#include "../protocol/groups/ChannelResetGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionFuture27NoEventsGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionFuture27NoMDFeedTypesGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionFuture27NoInstAttribGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionFuture27NoLotTypeRulesGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionSpread29NoEventsGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionSpread29NoMDFeedTypesGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionSpread29NoInstAttribGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionSpread29NoLotTypeRulesGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionSpread29NoLegsGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshBook32NoMDEntriesGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshBook32NoOrderIDEntriesGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshTrade36NoMDEntriesGroup.hpp"
#include "../protocol/groups/IncrementalRefreshVolumeGroup.hpp"
#include "../protocol/groups/SnapshotFullRefresh38NoMDEntriesGroup.hpp"
#include "../protocol/groups/RelatedSymGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionOption41NoEventsGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionOption41NoMDFeedTypesGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionOption41NoInstAttribGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionOption41NoLotTypeRulesGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionOption41NoUnderlyingsGroup.hpp"
#include "../protocol/groups/MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshTradeSummary42NoMDEntriesGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup.hpp"
#include "../protocol/groups/MDIncrementalRefreshOrderBook43NoMDEntriesGroup.hpp"
#include "../protocol/groups/SnapshotFullRefreshOrderBook44NoMDEntriesGroup.hpp"
#include "../parquet/Writer.hpp"
#include "../json/Writer.hpp"

namespace cme::mdp3::v8 {

///////////////////////////////////////////////////////////////////////
// Cme Sbe C++ parquet conversion manager
///////////////////////////////////////////////////////////////////////

// itch to parquet manager
struct Manager {

    ChannelResetGroupIterator channel_reset_group_iterator;
    IncrementalRefreshVolumeGroupIterator incremental_refresh_volume_group_iterator;
    MDIncrementalRefreshBook32NoMDEntriesGroupIterator m_d_incremental_refresh_book_32_no_m_d_entries_group_iterator;
    MDIncrementalRefreshBook32NoOrderIDEntriesGroupIterator m_d_incremental_refresh_book_32_no_order_i_d_entries_group_iterator;
    MDIncrementalRefreshDailyStatistics33NoMDEntriesGroupIterator m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_iterator;
    MDIncrementalRefreshLimitsBanding34NoMDEntriesGroupIterator m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_iterator;
    MDIncrementalRefreshOrderBook43NoMDEntriesGroupIterator m_d_incremental_refresh_order_book_43_no_m_d_entries_group_iterator;
    MDIncrementalRefreshSessionStatistics35NoMDEntriesGroupIterator m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_iterator;
    MDIncrementalRefreshTrade36NoMDEntriesGroupIterator m_d_incremental_refresh_trade_36_no_m_d_entries_group_iterator;
    MDIncrementalRefreshTradeSummary42NoMDEntriesGroupIterator m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_iterator;
    MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroupIterator m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_iterator;
    MDInstrumentDefinitionFuture27NoEventsGroupIterator m_d_instrument_definition_future_27_no_events_group_iterator;
    MDInstrumentDefinitionFuture27NoInstAttribGroupIterator m_d_instrument_definition_future_27_no_inst_attrib_group_iterator;
    MDInstrumentDefinitionFuture27NoLotTypeRulesGroupIterator m_d_instrument_definition_future_27_no_lot_type_rules_group_iterator;
    MDInstrumentDefinitionFuture27NoMDFeedTypesGroupIterator m_d_instrument_definition_future_27_no_m_d_feed_types_group_iterator;
    MDInstrumentDefinitionOption41NoEventsGroupIterator m_d_instrument_definition_option_41_no_events_group_iterator;
    MDInstrumentDefinitionOption41NoInstAttribGroupIterator m_d_instrument_definition_option_41_no_inst_attrib_group_iterator;
    MDInstrumentDefinitionOption41NoLotTypeRulesGroupIterator m_d_instrument_definition_option_41_no_lot_type_rules_group_iterator;
    MDInstrumentDefinitionOption41NoMDFeedTypesGroupIterator m_d_instrument_definition_option_41_no_m_d_feed_types_group_iterator;
    MDInstrumentDefinitionOption41NoRelatedInstrumentsGroupIterator m_d_instrument_definition_option_41_no_related_instruments_group_iterator;
    MDInstrumentDefinitionOption41NoUnderlyingsGroupIterator m_d_instrument_definition_option_41_no_underlyings_group_iterator;
    MDInstrumentDefinitionSpread29NoEventsGroupIterator m_d_instrument_definition_spread_29_no_events_group_iterator;
    MDInstrumentDefinitionSpread29NoInstAttribGroupIterator m_d_instrument_definition_spread_29_no_inst_attrib_group_iterator;
    MDInstrumentDefinitionSpread29NoLegsGroupIterator m_d_instrument_definition_spread_29_no_legs_group_iterator;
    MDInstrumentDefinitionSpread29NoLotTypeRulesGroupIterator m_d_instrument_definition_spread_29_no_lot_type_rules_group_iterator;
    MDInstrumentDefinitionSpread29NoMDFeedTypesGroupIterator m_d_instrument_definition_spread_29_no_m_d_feed_types_group_iterator;
    RelatedSymGroupIterator related_sym_group_iterator;
    SnapshotFullRefresh38NoMDEntriesGroupIterator snapshot_full_refresh_38_no_m_d_entries_group_iterator;
    SnapshotFullRefreshOrderBook44NoMDEntriesGroupIterator snapshot_full_refresh_order_book_44_no_m_d_entries_group_iterator;
    MessageIterator sbe;
    packet::Parser& parser;
    cme::Writer& record;
    const conversion::Options& options;
    json::Writer json_writer;

    explicit Manager(const conversion::Options& options, packet::Parser& parser, cme::Writer& record)
     : parser{ parser }, record{ record }, options{ options } {}

    // process udp packet
    void udp() {
        const auto& frame = parser.frame();
        sbe.initialize(frame.payload, frame.payload_len);

        if (sbe.template_id == 12) {
            return;
        }

        while (sbe.next()) {
            process(sbe.message, sbe.template_id);
        }

        packet_end();
    }

    void process(const std::byte* pointer, const std::uint16_t template_id) {
        switch (template_id) {
            case 4:
                process_channel_reset(pointer);
                break;

            case 12:
                process_admin_heartbeat(pointer);
                break;

            case 15:
                process_admin_login(pointer);
                break;

            case 16:
                process_admin_logout(pointer);
                break;

            case 27:
                process_md_instrument_definition_future(pointer);
                break;

            case 29:
                process_md_instrument_definition_spread(pointer);
                break;

            case 30:
                process_security_status(pointer);
                break;

            case 32:
                process_md_incremental_refresh_book(pointer);
                break;

            case 33:
                process_md_incremental_refresh_daily_statistics(pointer);
                break;

            case 34:
                process_md_incremental_refresh_limits_banding(pointer);
                break;

            case 35:
                process_md_incremental_refresh_session_statistics(pointer);
                break;

            case 36:
                process_md_incremental_refresh_trade(pointer);
                break;

            case 37:
                process_md_incremental_refresh_volume(pointer);
                break;

            case 38:
                process_snapshot_full_refresh(pointer);
                break;

            case 39:
                process_quote_request(pointer);
                break;

            case 41:
                process_md_instrument_definition_option(pointer);
                break;

            case 42:
                process_md_incremental_refresh_trade_summary(pointer);
                break;

            case 43:
                process_md_incremental_refresh_order_book(pointer);
                break;

            case 44:
                process_snapshot_full_refresh_order_book(pointer);
                break;

            default:
                break;
        }
    }

    void process_channel_reset(const std::byte* pointer) {
        const auto message = ChannelReset::parse(pointer);

        record.event_type.set("Channel Reset");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: Channel Reset Group (serialized as JSON)
        json_writer.start_array();
        channel_reset_group_iterator.initialize(pointer + sizeof(ChannelReset));
        while (channel_reset_group_iterator.next()) {
            const auto* entry = ChannelResetGroup::parse(channel_reset_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Appl Id", entry->appl_id.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.channel_reset_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_admin_heartbeat(const std::byte* pointer) {
        record.event_type.set("Admin Heartbeat");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());

        record.write();
        record.reset();
    }

    void process_admin_login(const std::byte* pointer) {
        const auto message = AdminLogin::parse(pointer);

        record.event_type.set("Admin Login");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.heart_bt_int.set(message->heart_bt_int.get());

        record.write();
        record.reset();
    }

    void process_admin_logout(const std::byte* pointer) {
        const auto message = AdminLogout::parse(pointer);

        record.event_type.set("Admin Logout");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.text.set(message->text.get());

        record.write();
        record.reset();
    }

    void process_md_instrument_definition_future(const std::byte* pointer) {
        const auto message = MdInstrumentDefinitionFuture::parse(pointer);

        record.event_type.set("Md Instrument Definition Future");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.tot_num_reports_optional.set(message->tot_num_reports_optional.get());
        record.security_update_action.set(message->security_update_action.get());
        record.last_update_time.set(message->last_update_time.get());
        record.md_security_trading_status.set(message->md_security_trading_status.get());
        record.appl_id.set(message->appl_id.get());
        record.market_segment_id.set(message->market_segment_id.get());
        record.underlying_product.set(message->underlying_product.get());
        record.security_exchange.set(message->security_exchange.get());
        record.security_group.set(message->security_group.get());
        record.asset.set(message->asset.get());
        record.symbol.set(message->symbol.get());
        record.security_id.set(message->security_id.get());
        record.security_type.set(message->security_type.get());
        record.cfi_code.set(message->cfi_code.get());
        record.currency.set(message->currency.get());
        record.settl_currency.set(message->settl_currency.get());
        record.match_algorithm.set(message->match_algorithm.get());
        record.min_trade_vol.set(message->min_trade_vol.get());
        record.max_trade_vol.set(message->max_trade_vol.get());
        record.min_price_increment.set(message->min_price_increment.get());
        record.display_factor.set(message->display_factor.get());
        record.main_fraction.set(message->main_fraction.get());
        record.sub_fraction.set(message->sub_fraction.get());
        record.price_display_format.set(message->price_display_format.get());
        record.unit_of_measure.set(message->unit_of_measure.get());
        record.unit_of_measure_qty.set(message->unit_of_measure_qty.get());
        record.trading_reference_price.set(message->trading_reference_price.get());
        record.open_interest_qty.set(message->open_interest_qty.get());
        record.cleared_volume.set(message->cleared_volume.get());
        record.high_limit_price.set(message->high_limit_price.get());
        record.low_limit_price.set(message->low_limit_price.get());
        record.max_price_variation.set(message->max_price_variation.get());
        record.decay_quantity.set(message->decay_quantity.get());
        record.decay_start_date.set(message->decay_start_date.get());
        record.original_contract_size.set(message->original_contract_size.get());
        record.contract_multiplier.set(message->contract_multiplier.get());
        record.contract_multiplier_unit.set(message->contract_multiplier_unit.get());
        record.flow_schedule_type.set(message->flow_schedule_type.get());
        record.min_price_increment_amount.set(message->min_price_increment_amount.get());
        record.user_defined_instrument.set(message->user_defined_instrument.get());
        record.trading_reference_date.set(message->trading_reference_date.get());

        // repeating group: M D Instrument Definition Future 27 No Events Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_future_27_no_events_group_iterator.initialize(pointer + sizeof(MdInstrumentDefinitionFuture));
        while (m_d_instrument_definition_future_27_no_events_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionFuture27NoEventsGroup::parse(m_d_instrument_definition_future_27_no_events_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Event Type", entry->event_type.get());
            json_writer.field("Event Time", entry->event_time.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_future_27_no_events_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Future 27 No M D Feed Types Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_future_27_no_m_d_feed_types_group_iterator.initialize(m_d_instrument_definition_future_27_no_events_group_iterator.current);
        while (m_d_instrument_definition_future_27_no_m_d_feed_types_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionFuture27NoMDFeedTypesGroup::parse(m_d_instrument_definition_future_27_no_m_d_feed_types_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Feed Type", entry->md_feed_type.get());
            json_writer.field("Market Depth", entry->market_depth.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_future_27_no_m_d_feed_types_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Future 27 No Inst Attrib Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_future_27_no_inst_attrib_group_iterator.initialize(m_d_instrument_definition_future_27_no_m_d_feed_types_group_iterator.current);
        while (m_d_instrument_definition_future_27_no_inst_attrib_group_iterator.next()) {
            json_writer.start_element();
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_future_27_no_inst_attrib_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Future 27 No Lot Type Rules Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_future_27_no_lot_type_rules_group_iterator.initialize(m_d_instrument_definition_future_27_no_inst_attrib_group_iterator.current);
        while (m_d_instrument_definition_future_27_no_lot_type_rules_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionFuture27NoLotTypeRulesGroup::parse(m_d_instrument_definition_future_27_no_lot_type_rules_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Lot Type", entry->lot_type.get());
            json_writer.field("Min Lot Size", entry->min_lot_size.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_future_27_no_lot_type_rules_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_instrument_definition_spread(const std::byte* pointer) {
        const auto message = MdInstrumentDefinitionSpread::parse(pointer);

        record.event_type.set("Md Instrument Definition Spread");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.tot_num_reports_optional.set(message->tot_num_reports_optional.get());
        record.security_update_action.set(message->security_update_action.get());
        record.last_update_time.set(message->last_update_time.get());
        record.md_security_trading_status.set(message->md_security_trading_status.get());
        record.appl_id.set(message->appl_id.get());
        record.market_segment_id.set(message->market_segment_id.get());
        record.underlying_product_optional.set(message->underlying_product_optional.get());
        record.security_exchange.set(message->security_exchange.get());
        record.security_group.set(message->security_group.get());
        record.asset.set(message->asset.get());
        record.symbol.set(message->symbol.get());
        record.security_id.set(message->security_id.get());
        record.security_type.set(message->security_type.get());
        record.cfi_code.set(message->cfi_code.get());
        record.currency.set(message->currency.get());
        record.security_sub_type.set(message->security_sub_type.get());
        record.user_defined_instrument.set(message->user_defined_instrument.get());
        record.match_algorithm.set(message->match_algorithm.get());
        record.min_trade_vol.set(message->min_trade_vol.get());
        record.max_trade_vol.set(message->max_trade_vol.get());
        record.min_price_increment.set(message->min_price_increment.get());
        record.display_factor.set(message->display_factor.get());
        record.price_display_format.set(message->price_display_format.get());
        record.price_ratio.set(message->price_ratio.get());
        record.tick_rule.set(message->tick_rule.get());
        record.unit_of_measure.set(message->unit_of_measure.get());
        record.trading_reference_price.set(message->trading_reference_price.get());
        record.open_interest_qty.set(message->open_interest_qty.get());
        record.cleared_volume.set(message->cleared_volume.get());
        record.high_limit_price.set(message->high_limit_price.get());
        record.low_limit_price.set(message->low_limit_price.get());
        record.max_price_variation.set(message->max_price_variation.get());
        record.main_fraction.set(message->main_fraction.get());
        record.sub_fraction.set(message->sub_fraction.get());
        record.trading_reference_date.set(message->trading_reference_date.get());

        // repeating group: M D Instrument Definition Spread 29 No Events Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_spread_29_no_events_group_iterator.initialize(pointer + sizeof(MdInstrumentDefinitionSpread));
        while (m_d_instrument_definition_spread_29_no_events_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionSpread29NoEventsGroup::parse(m_d_instrument_definition_spread_29_no_events_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Event Type", entry->event_type.get());
            json_writer.field("Event Time", entry->event_time.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_spread_29_no_events_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Spread 29 No M D Feed Types Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_spread_29_no_m_d_feed_types_group_iterator.initialize(m_d_instrument_definition_spread_29_no_events_group_iterator.current);
        while (m_d_instrument_definition_spread_29_no_m_d_feed_types_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionSpread29NoMDFeedTypesGroup::parse(m_d_instrument_definition_spread_29_no_m_d_feed_types_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Feed Type", entry->md_feed_type.get());
            json_writer.field("Market Depth", entry->market_depth.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_spread_29_no_m_d_feed_types_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Spread 29 No Inst Attrib Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_spread_29_no_inst_attrib_group_iterator.initialize(m_d_instrument_definition_spread_29_no_m_d_feed_types_group_iterator.current);
        while (m_d_instrument_definition_spread_29_no_inst_attrib_group_iterator.next()) {
            json_writer.start_element();
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_spread_29_no_inst_attrib_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Spread 29 No Lot Type Rules Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_spread_29_no_lot_type_rules_group_iterator.initialize(m_d_instrument_definition_spread_29_no_inst_attrib_group_iterator.current);
        while (m_d_instrument_definition_spread_29_no_lot_type_rules_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionSpread29NoLotTypeRulesGroup::parse(m_d_instrument_definition_spread_29_no_lot_type_rules_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Lot Type", entry->lot_type.get());
            json_writer.field("Min Lot Size", entry->min_lot_size.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_spread_29_no_lot_type_rules_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Spread 29 No Legs Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_spread_29_no_legs_group_iterator.initialize(m_d_instrument_definition_spread_29_no_lot_type_rules_group_iterator.current);
        while (m_d_instrument_definition_spread_29_no_legs_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionSpread29NoLegsGroup::parse(m_d_instrument_definition_spread_29_no_legs_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Leg Security Id", entry->leg_security_id.get());
            json_writer.field("Leg Side", entry->leg_side.get());
            json_writer.field("Leg Ratio Qty", entry->leg_ratio_qty.get());
            json_writer.field("Leg Price", entry->leg_price.get());
            json_writer.field("Leg Option Delta", entry->leg_option_delta.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_spread_29_no_legs_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_security_status(const std::byte* pointer) {
        const auto message = SecurityStatus::parse(pointer);

        record.event_type.set("Security Status");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());
        record.security_group.set(message->security_group.get());
        record.asset.set(message->asset.get());
        record.security_id_optional.set(message->security_id_optional.get());
        record.trade_date.set(message->trade_date.get());
        record.security_trading_status.set(message->security_trading_status.get());
        record.halt_reason.set(message->halt_reason.get());
        record.security_trading_event.set(message->security_trading_event.get());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_book(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshBook::parse(pointer);

        record.event_type.set("Md Incremental Refresh Book");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: M D Incremental Refresh Book 32 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_book_32_no_m_d_entries_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshBook));
        while (m_d_incremental_refresh_book_32_no_m_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshBook32NoMDEntriesGroup::parse(m_d_incremental_refresh_book_32_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Entry Px Optional", entry->md_entry_px_optional.get());
            json_writer.field("Md Entry Size Optional", entry->md_entry_size_optional.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Rpt Seq", entry->rpt_seq.get());
            json_writer.field("Number Of Orders", entry->number_of_orders.get());
            json_writer.field("Md Price Level", entry->md_price_level.get());
            json_writer.field("Md Update Action", entry->md_update_action.get());
            json_writer.field("Md Entry Type Book", entry->md_entry_type_book.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_book_32_no_m_d_entries_group.set(json_writer.view());

        // repeating group: M D Incremental Refresh Book 32 No Order I D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_book_32_no_order_i_d_entries_group_iterator.initialize(m_d_incremental_refresh_book_32_no_m_d_entries_group_iterator.current);
        while (m_d_incremental_refresh_book_32_no_order_i_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshBook32NoOrderIDEntriesGroup::parse(m_d_incremental_refresh_book_32_no_order_i_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Order Id", entry->order_id.get());
            json_writer.field("Md Order Priority", entry->md_order_priority.get());
            json_writer.field("Md Display Qty Optional", entry->md_display_qty_optional.get());
            json_writer.field("Reference Id", entry->reference_id.get());
            json_writer.field("Order Update Action", entry->order_update_action.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_book_32_no_order_i_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_daily_statistics(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshDailyStatistics::parse(pointer);

        record.event_type.set("Md Incremental Refresh Daily Statistics");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: M D Incremental Refresh Daily Statistics 33 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshDailyStatistics));
        while (m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup::parse(m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Entry Px Optional", entry->md_entry_px_optional.get());
            json_writer.field("Md Entry Size Optional", entry->md_entry_size_optional.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Rpt Seq", entry->rpt_seq.get());
            json_writer.field("Trading Reference Date", entry->trading_reference_date.get());
            json_writer.field("Md Update Action", entry->md_update_action.get());
            json_writer.field("Md Entry Type Daily Statistics", entry->md_entry_type_daily_statistics.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_limits_banding(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshLimitsBanding::parse(pointer);

        record.event_type.set("Md Incremental Refresh Limits Banding");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: M D Incremental Refresh Limits Banding 34 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshLimitsBanding));
        while (m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup::parse(m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("High Limit Price", entry->high_limit_price.get());
            json_writer.field("Low Limit Price", entry->low_limit_price.get());
            json_writer.field("Max Price Variation", entry->max_price_variation.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Rpt Seq", entry->rpt_seq.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_session_statistics(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshSessionStatistics::parse(pointer);

        record.event_type.set("Md Incremental Refresh Session Statistics");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: M D Incremental Refresh Session Statistics 35 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshSessionStatistics));
        while (m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup::parse(m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Entry Px", entry->md_entry_px.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Rpt Seq", entry->rpt_seq.get());
            json_writer.field("Open Close Settl Flag", entry->open_close_settl_flag.get());
            json_writer.field("Md Update Action", entry->md_update_action.get());
            json_writer.field("Md Entry Type Statistics", entry->md_entry_type_statistics.get());
            json_writer.field("Md Entry Size Optional", entry->md_entry_size_optional.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_trade(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshTrade::parse(pointer);

        record.event_type.set("Md Incremental Refresh Trade");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: M D Incremental Refresh Trade 36 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_trade_36_no_m_d_entries_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshTrade));
        while (m_d_incremental_refresh_trade_36_no_m_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshTrade36NoMDEntriesGroup::parse(m_d_incremental_refresh_trade_36_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Entry Px", entry->md_entry_px.get());
            json_writer.field("Md Entry Size", entry->md_entry_size.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Rpt Seq", entry->rpt_seq.get());
            json_writer.field("Number Of Orders", entry->number_of_orders.get());
            json_writer.field("Trade Id", entry->trade_id.get());
            json_writer.field("Aggressor Side", entry->aggressor_side.get());
            json_writer.field("Md Update Action", entry->md_update_action.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_trade_36_no_m_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_volume(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshVolume::parse(pointer);

        record.event_type.set("Md Incremental Refresh Volume");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: Incremental Refresh Volume Group (serialized as JSON)
        json_writer.start_array();
        incremental_refresh_volume_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshVolume));
        while (incremental_refresh_volume_group_iterator.next()) {
            const auto* entry = IncrementalRefreshVolumeGroup::parse(incremental_refresh_volume_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Entry Size", entry->md_entry_size.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Rpt Seq", entry->rpt_seq.get());
            json_writer.field("Md Update Action", entry->md_update_action.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.incremental_refresh_volume_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_snapshot_full_refresh(const std::byte* pointer) {
        const auto message = SnapshotFullRefresh::parse(pointer);

        record.event_type.set("Snapshot Full Refresh");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.last_msg_seq_num_processed.set(message->last_msg_seq_num_processed.get());
        record.tot_num_reports.set(message->tot_num_reports.get());
        record.security_id.set(message->security_id.get());
        record.rpt_seq.set(message->rpt_seq.get());
        record.transact_time.set(message->transact_time.get());
        record.last_update_time.set(message->last_update_time.get());
        record.trade_date.set(message->trade_date.get());
        record.md_security_trading_status.set(message->md_security_trading_status.get());
        record.high_limit_price.set(message->high_limit_price.get());
        record.low_limit_price.set(message->low_limit_price.get());
        record.max_price_variation.set(message->max_price_variation.get());

        // repeating group: Snapshot Full Refresh 38 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        snapshot_full_refresh_38_no_m_d_entries_group_iterator.initialize(pointer + sizeof(SnapshotFullRefresh));
        while (snapshot_full_refresh_38_no_m_d_entries_group_iterator.next()) {
            const auto* entry = SnapshotFullRefresh38NoMDEntriesGroup::parse(snapshot_full_refresh_38_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Entry Px Optional", entry->md_entry_px_optional.get());
            json_writer.field("Md Entry Size Optional", entry->md_entry_size_optional.get());
            json_writer.field("Number Of Orders", entry->number_of_orders.get());
            json_writer.field("Md Price Level Optional", entry->md_price_level_optional.get());
            json_writer.field("Trading Reference Date", entry->trading_reference_date.get());
            json_writer.field("Open Close Settl Flag", entry->open_close_settl_flag.get());
            json_writer.field("Md Entry Type ", entry->md_entry_type.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.snapshot_full_refresh_38_no_m_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_quote_request(const std::byte* pointer) {
        const auto message = QuoteRequest::parse(pointer);

        record.event_type.set("Quote Request");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());
        record.quote_req_id.set(message->quote_req_id.get());

        // repeating group: Related Sym Group (serialized as JSON)
        json_writer.start_array();
        related_sym_group_iterator.initialize(pointer + sizeof(QuoteRequest));
        while (related_sym_group_iterator.next()) {
            const auto* entry = RelatedSymGroup::parse(related_sym_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Symbol", entry->symbol.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Order Qty", entry->order_qty.get());
            json_writer.field("Quote Type", entry->quote_type.get());
            json_writer.field("Side", entry->side.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.related_sym_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_instrument_definition_option(const std::byte* pointer) {
        const auto message = MdInstrumentDefinitionOption::parse(pointer);

        record.event_type.set("Md Instrument Definition Option");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.tot_num_reports_optional.set(message->tot_num_reports_optional.get());
        record.security_update_action.set(message->security_update_action.get());
        record.last_update_time.set(message->last_update_time.get());
        record.md_security_trading_status.set(message->md_security_trading_status.get());
        record.appl_id.set(message->appl_id.get());
        record.market_segment_id.set(message->market_segment_id.get());
        record.underlying_product.set(message->underlying_product.get());
        record.security_exchange.set(message->security_exchange.get());
        record.security_group.set(message->security_group.get());
        record.asset.set(message->asset.get());
        record.symbol.set(message->symbol.get());
        record.security_id.set(message->security_id.get());
        record.security_type.set(message->security_type.get());
        record.cfi_code.set(message->cfi_code.get());
        record.put_or_call.set(message->put_or_call.get());
        record.currency.set(message->currency.get());
        record.strike_price.set(message->strike_price.get());
        record.strike_currency.set(message->strike_currency.get());
        record.settl_currency.set(message->settl_currency.get());
        record.min_cab_price.set(message->min_cab_price.get());
        record.match_algorithm.set(message->match_algorithm.get());
        record.min_trade_vol.set(message->min_trade_vol.get());
        record.max_trade_vol.set(message->max_trade_vol.get());
        record.min_price_increment_optional.set(message->min_price_increment_optional.get());
        record.min_price_increment_amount.set(message->min_price_increment_amount.get());
        record.display_factor.set(message->display_factor.get());
        record.tick_rule.set(message->tick_rule.get());
        record.main_fraction.set(message->main_fraction.get());
        record.sub_fraction.set(message->sub_fraction.get());
        record.price_display_format.set(message->price_display_format.get());
        record.unit_of_measure.set(message->unit_of_measure.get());
        record.unit_of_measure_qty.set(message->unit_of_measure_qty.get());
        record.trading_reference_price.set(message->trading_reference_price.get());
        record.cleared_volume.set(message->cleared_volume.get());
        record.open_interest_qty.set(message->open_interest_qty.get());
        record.low_limit_price.set(message->low_limit_price.get());
        record.high_limit_price.set(message->high_limit_price.get());
        record.user_defined_instrument.set(message->user_defined_instrument.get());
        record.trading_reference_date.set(message->trading_reference_date.get());

        // repeating group: M D Instrument Definition Option 41 No Events Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_option_41_no_events_group_iterator.initialize(pointer + sizeof(MdInstrumentDefinitionOption));
        while (m_d_instrument_definition_option_41_no_events_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionOption41NoEventsGroup::parse(m_d_instrument_definition_option_41_no_events_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Event Type", entry->event_type.get());
            json_writer.field("Event Time", entry->event_time.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_option_41_no_events_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Option 41 No M D Feed Types Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_option_41_no_m_d_feed_types_group_iterator.initialize(m_d_instrument_definition_option_41_no_events_group_iterator.current);
        while (m_d_instrument_definition_option_41_no_m_d_feed_types_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionOption41NoMDFeedTypesGroup::parse(m_d_instrument_definition_option_41_no_m_d_feed_types_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Feed Type", entry->md_feed_type.get());
            json_writer.field("Market Depth", entry->market_depth.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_option_41_no_m_d_feed_types_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Option 41 No Inst Attrib Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_option_41_no_inst_attrib_group_iterator.initialize(m_d_instrument_definition_option_41_no_m_d_feed_types_group_iterator.current);
        while (m_d_instrument_definition_option_41_no_inst_attrib_group_iterator.next()) {
            json_writer.start_element();
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_option_41_no_inst_attrib_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Option 41 No Lot Type Rules Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_option_41_no_lot_type_rules_group_iterator.initialize(m_d_instrument_definition_option_41_no_inst_attrib_group_iterator.current);
        while (m_d_instrument_definition_option_41_no_lot_type_rules_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionOption41NoLotTypeRulesGroup::parse(m_d_instrument_definition_option_41_no_lot_type_rules_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Lot Type", entry->lot_type.get());
            json_writer.field("Min Lot Size", entry->min_lot_size.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_option_41_no_lot_type_rules_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Option 41 No Underlyings Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_option_41_no_underlyings_group_iterator.initialize(m_d_instrument_definition_option_41_no_lot_type_rules_group_iterator.current);
        while (m_d_instrument_definition_option_41_no_underlyings_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionOption41NoUnderlyingsGroup::parse(m_d_instrument_definition_option_41_no_underlyings_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Underlying Security Id", entry->underlying_security_id.get());
            json_writer.field("Underlying Symbol", entry->underlying_symbol.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_option_41_no_underlyings_group.set(json_writer.view());

        // repeating group: M D Instrument Definition Option 41 No Related Instruments Group (serialized as JSON)
        json_writer.start_array();
        m_d_instrument_definition_option_41_no_related_instruments_group_iterator.initialize(m_d_instrument_definition_option_41_no_underlyings_group_iterator.current);
        while (m_d_instrument_definition_option_41_no_related_instruments_group_iterator.next()) {
            const auto* entry = MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup::parse(m_d_instrument_definition_option_41_no_related_instruments_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Related Security Id", entry->related_security_id.get());
            json_writer.field("Related Symbol", entry->related_symbol.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_instrument_definition_option_41_no_related_instruments_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_trade_summary(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshTradeSummary::parse(pointer);

        record.event_type.set("Md Incremental Refresh Trade Summary");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: M D Incremental Refresh Trade Summary 42 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshTradeSummary));
        while (m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshTradeSummary42NoMDEntriesGroup::parse(m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Md Entry Px", entry->md_entry_px.get());
            json_writer.field("Md Entry Size", entry->md_entry_size.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Rpt Seq", entry->rpt_seq.get());
            json_writer.field("Number Of Orders", entry->number_of_orders.get());
            json_writer.field("Aggressor Side", entry->aggressor_side.get());
            json_writer.field("Md Update Action", entry->md_update_action.get());
            json_writer.field("Md Trade Entry Id", entry->md_trade_entry_id.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group.set(json_writer.view());

        // repeating group: M D Incremental Refresh Trade Summary 42 No Order I D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_iterator.initialize(m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_iterator.current);
        while (m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup::parse(m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Order Id", entry->order_id.get());
            json_writer.field("Last Qty", entry->last_qty.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_md_incremental_refresh_order_book(const std::byte* pointer) {
        const auto message = MdIncrementalRefreshOrderBook::parse(pointer);

        record.event_type.set("Md Incremental Refresh Order Book");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: M D Incremental Refresh Order Book 43 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        m_d_incremental_refresh_order_book_43_no_m_d_entries_group_iterator.initialize(pointer + sizeof(MdIncrementalRefreshOrderBook));
        while (m_d_incremental_refresh_order_book_43_no_m_d_entries_group_iterator.next()) {
            const auto* entry = MDIncrementalRefreshOrderBook43NoMDEntriesGroup::parse(m_d_incremental_refresh_order_book_43_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Order Id Optional", entry->order_id_optional.get());
            json_writer.field("Md Order Priority", entry->md_order_priority.get());
            json_writer.field("Md Entry Px Optional", entry->md_entry_px_optional.get());
            json_writer.field("Md Display Qty Optional", entry->md_display_qty_optional.get());
            json_writer.field("Security Id", entry->security_id.get());
            json_writer.field("Md Update Action", entry->md_update_action.get());
            json_writer.field("Md Entry Type Book", entry->md_entry_type_book.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.m_d_incremental_refresh_order_book_43_no_m_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    void process_snapshot_full_refresh_order_book(const std::byte* pointer) {
        const auto message = SnapshotFullRefreshOrderBook::parse(pointer);

        record.event_type.set("Snapshot Full Refresh Order Book");
        record.packet_sequence_number.set(sbe.binary_packet_header->packet_sequence_number.get());
        record.sending_time.set(sbe.binary_packet_header->sending_time.get());
        record.last_msg_seq_num_processed.set(message->last_msg_seq_num_processed.get());
        record.tot_num_reports.set(message->tot_num_reports.get());
        record.security_id.set(message->security_id.get());
        record.no_chunks.set(message->no_chunks.get());
        record.current_chunk.set(message->current_chunk.get());
        record.transact_time.set(message->transact_time.get());

        // repeating group: Snapshot Full Refresh Order Book 44 No M D Entries Group (serialized as JSON)
        json_writer.start_array();
        snapshot_full_refresh_order_book_44_no_m_d_entries_group_iterator.initialize(pointer + sizeof(SnapshotFullRefreshOrderBook));
        while (snapshot_full_refresh_order_book_44_no_m_d_entries_group_iterator.next()) {
            const auto* entry = SnapshotFullRefreshOrderBook44NoMDEntriesGroup::parse(snapshot_full_refresh_order_book_44_no_m_d_entries_group_iterator.entry);
            json_writer.start_element();
            json_writer.field("Order Id", entry->order_id.get());
            json_writer.field("Md Order Priority", entry->md_order_priority.get());
            json_writer.field("Md Entry Px", entry->md_entry_px.get());
            json_writer.field("Md Display Qty", entry->md_display_qty.get());
            json_writer.field("Md Entry Type Book", entry->md_entry_type_book.get());
            json_writer.end_element();
        }
        json_writer.finish_array();
        record.snapshot_full_refresh_order_book_44_no_m_d_entries_group.set(json_writer.view());

        record.write();
        record.reset();
    }

    // packet end action
    void packet_end() {
    }
};
}
