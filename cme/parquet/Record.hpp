#pragma once

#include <memory>

#include "fields/EventType.hpp"
#include "fields/TransactTime.hpp"
#include "fields/BlockLength.hpp"
#include "fields/NumInGroup.hpp"
#include "fields/ApplId.hpp"
#include "fields/HeartBtInt.hpp"
#include "fields/Text.hpp"
#include "fields/TotNumReportsOptional.hpp"
#include "fields/SecurityUpdateAction.hpp"
#include "fields/LastUpdateTime.hpp"
#include "fields/MdSecurityTradingStatus.hpp"
#include "fields/MarketSegmentId.hpp"
#include "fields/UnderlyingProduct.hpp"
#include "fields/SecurityExchange.hpp"
#include "fields/SecurityGroup.hpp"
#include "fields/Asset.hpp"
#include "fields/Symbol.hpp"
#include "fields/SecurityId.hpp"
#include "fields/SecurityType.hpp"
#include "fields/CfiCode.hpp"
#include "fields/Year.hpp"
#include "fields/Month.hpp"
#include "fields/Day.hpp"
#include "fields/Week.hpp"
#include "fields/Currency.hpp"
#include "fields/SettlCurrency.hpp"
#include "fields/MatchAlgorithm.hpp"
#include "fields/MinTradeVol.hpp"
#include "fields/MaxTradeVol.hpp"
#include "fields/MinPriceIncrement.hpp"
#include "fields/DisplayFactor.hpp"
#include "fields/MainFraction.hpp"
#include "fields/SubFraction.hpp"
#include "fields/PriceDisplayFormat.hpp"
#include "fields/UnitOfMeasure.hpp"
#include "fields/UnitOfMeasureQty.hpp"
#include "fields/TradingReferencePrice.hpp"
#include "fields/OpenInterestQty.hpp"
#include "fields/ClearedVolume.hpp"
#include "fields/HighLimitPrice.hpp"
#include "fields/LowLimitPrice.hpp"
#include "fields/MaxPriceVariation.hpp"
#include "fields/DecayQuantity.hpp"
#include "fields/DecayStartDate.hpp"
#include "fields/OriginalContractSize.hpp"
#include "fields/ContractMultiplier.hpp"
#include "fields/ContractMultiplierUnit.hpp"
#include "fields/FlowScheduleType.hpp"
#include "fields/MinPriceIncrementAmount.hpp"
#include "fields/UserDefinedInstrument.hpp"
#include "fields/TradingReferenceDate.hpp"
#include "fields/EventTime.hpp"
#include "fields/MdFeedType.hpp"
#include "fields/MarketDepth.hpp"
#include "fields/LotType.hpp"
#include "fields/MinLotSize.hpp"
#include "fields/UnderlyingProductOptional.hpp"
#include "fields/SecuritySubType.hpp"
#include "fields/PriceRatio.hpp"
#include "fields/TickRule.hpp"
#include "fields/LegSecurityId.hpp"
#include "fields/LegSide.hpp"
#include "fields/LegRatioQty.hpp"
#include "fields/LegPrice.hpp"
#include "fields/LegOptionDelta.hpp"
#include "fields/SecurityIdOptional.hpp"
#include "fields/TradeDate.hpp"
#include "fields/SecurityTradingStatus.hpp"
#include "fields/HaltReason.hpp"
#include "fields/SecurityTradingEvent.hpp"
#include "fields/MdEntryPxOptional.hpp"
#include "fields/MdEntrySizeOptional.hpp"
#include "fields/RptSeq.hpp"
#include "fields/NumberOfOrders.hpp"
#include "fields/MdPriceLevel.hpp"
#include "fields/MdUpdateAction.hpp"
#include "fields/MdEntryTypeBook.hpp"
#include "fields/OrderId.hpp"
#include "fields/MdOrderPriority.hpp"
#include "fields/MdDisplayQtyOptional.hpp"
#include "fields/ReferenceId.hpp"
#include "fields/OrderUpdateAction.hpp"
#include "fields/MdEntryTypeDailyStatistics.hpp"
#include "fields/MdEntryPx.hpp"
#include "fields/OpenCloseSettlFlag.hpp"
#include "fields/MdEntryTypeStatistics.hpp"
#include "fields/MdEntrySize.hpp"
#include "fields/TradeId.hpp"
#include "fields/AggressorSide.hpp"
#include "fields/LastMsgSeqNumProcessed.hpp"
#include "fields/TotNumReports.hpp"
#include "fields/MdPriceLevelOptional.hpp"
#include "fields/MdEntryType.hpp"
#include "fields/QuoteReqId.hpp"
#include "fields/OrderQty.hpp"
#include "fields/QuoteType.hpp"
#include "fields/Side.hpp"
#include "fields/PutOrCall.hpp"
#include "fields/StrikePrice.hpp"
#include "fields/StrikeCurrency.hpp"
#include "fields/MinCabPrice.hpp"
#include "fields/MinPriceIncrementOptional.hpp"
#include "fields/UnderlyingSecurityId.hpp"
#include "fields/UnderlyingSymbol.hpp"
#include "fields/RelatedSecurityId.hpp"
#include "fields/RelatedSymbol.hpp"
#include "fields/MdTradeEntryId.hpp"
#include "fields/LastQty.hpp"
#include "fields/OrderIdOptional.hpp"
#include "fields/NoChunks.hpp"
#include "fields/CurrentChunk.hpp"
#include "fields/MdDisplayQty.hpp"
#include "fields/ChannelResetGroup.hpp"
#include "fields/MDInstrumentDefinitionFuture27NoEventsGroup.hpp"
#include "fields/MDInstrumentDefinitionFuture27NoMDFeedTypesGroup.hpp"
#include "fields/MDInstrumentDefinitionFuture27NoInstAttribGroup.hpp"
#include "fields/MDInstrumentDefinitionFuture27NoLotTypeRulesGroup.hpp"
#include "fields/MDInstrumentDefinitionSpread29NoEventsGroup.hpp"
#include "fields/MDInstrumentDefinitionSpread29NoMDFeedTypesGroup.hpp"
#include "fields/MDInstrumentDefinitionSpread29NoInstAttribGroup.hpp"
#include "fields/MDInstrumentDefinitionSpread29NoLotTypeRulesGroup.hpp"
#include "fields/MDInstrumentDefinitionSpread29NoLegsGroup.hpp"
#include "fields/MDIncrementalRefreshBook32NoMDEntriesGroup.hpp"
#include "fields/MDIncrementalRefreshBook32NoOrderIDEntriesGroup.hpp"
#include "fields/MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup.hpp"
#include "fields/MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup.hpp"
#include "fields/MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup.hpp"
#include "fields/MDIncrementalRefreshTrade36NoMDEntriesGroup.hpp"
#include "fields/IncrementalRefreshVolumeGroup.hpp"
#include "fields/SnapshotFullRefresh38NoMDEntriesGroup.hpp"
#include "fields/RelatedSymGroup.hpp"
#include "fields/MDInstrumentDefinitionOption41NoEventsGroup.hpp"
#include "fields/MDInstrumentDefinitionOption41NoMDFeedTypesGroup.hpp"
#include "fields/MDInstrumentDefinitionOption41NoInstAttribGroup.hpp"
#include "fields/MDInstrumentDefinitionOption41NoLotTypeRulesGroup.hpp"
#include "fields/MDInstrumentDefinitionOption41NoUnderlyingsGroup.hpp"
#include "fields/MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup.hpp"
#include "fields/MDIncrementalRefreshTradeSummary42NoMDEntriesGroup.hpp"
#include "fields/MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup.hpp"
#include "fields/MDIncrementalRefreshOrderBook43NoMDEntriesGroup.hpp"
#include "fields/SnapshotFullRefreshOrderBook44NoMDEntriesGroup.hpp"

namespace cme {
struct ArrowRecord {

    EventType event_type;
    TransactTime transact_time;
    BlockLength block_length;
    NumInGroup num_in_group;
    ApplId appl_id;
    HeartBtInt heart_bt_int;
    Text text;
    TotNumReportsOptional tot_num_reports_optional;
    SecurityUpdateAction security_update_action;
    LastUpdateTime last_update_time;
    MdSecurityTradingStatus md_security_trading_status;
    MarketSegmentId market_segment_id;
    UnderlyingProduct underlying_product;
    SecurityExchange security_exchange;
    SecurityGroup security_group;
    Asset asset;
    Symbol symbol;
    SecurityId security_id;
    SecurityType security_type;
    CfiCode cfi_code;
    Year year;
    Month month;
    Day day;
    Week week;
    Currency currency;
    SettlCurrency settl_currency;
    MatchAlgorithm match_algorithm;
    MinTradeVol min_trade_vol;
    MaxTradeVol max_trade_vol;
    MinPriceIncrement min_price_increment;
    DisplayFactor display_factor;
    MainFraction main_fraction;
    SubFraction sub_fraction;
    PriceDisplayFormat price_display_format;
    UnitOfMeasure unit_of_measure;
    UnitOfMeasureQty unit_of_measure_qty;
    TradingReferencePrice trading_reference_price;
    OpenInterestQty open_interest_qty;
    ClearedVolume cleared_volume;
    HighLimitPrice high_limit_price;
    LowLimitPrice low_limit_price;
    MaxPriceVariation max_price_variation;
    DecayQuantity decay_quantity;
    DecayStartDate decay_start_date;
    OriginalContractSize original_contract_size;
    ContractMultiplier contract_multiplier;
    ContractMultiplierUnit contract_multiplier_unit;
    FlowScheduleType flow_schedule_type;
    MinPriceIncrementAmount min_price_increment_amount;
    UserDefinedInstrument user_defined_instrument;
    TradingReferenceDate trading_reference_date;
    EventTime event_time;
    MdFeedType md_feed_type;
    MarketDepth market_depth;
    LotType lot_type;
    MinLotSize min_lot_size;
    UnderlyingProductOptional underlying_product_optional;
    SecuritySubType security_sub_type;
    PriceRatio price_ratio;
    TickRule tick_rule;
    LegSecurityId leg_security_id;
    LegSide leg_side;
    LegRatioQty leg_ratio_qty;
    LegPrice leg_price;
    LegOptionDelta leg_option_delta;
    SecurityIdOptional security_id_optional;
    TradeDate trade_date;
    SecurityTradingStatus security_trading_status;
    HaltReason halt_reason;
    SecurityTradingEvent security_trading_event;
    MdEntryPxOptional md_entry_px_optional;
    MdEntrySizeOptional md_entry_size_optional;
    RptSeq rpt_seq;
    NumberOfOrders number_of_orders;
    MdPriceLevel md_price_level;
    MdUpdateAction md_update_action;
    MdEntryTypeBook md_entry_type_book;
    OrderId order_id;
    MdOrderPriority md_order_priority;
    MdDisplayQtyOptional md_display_qty_optional;
    ReferenceId reference_id;
    OrderUpdateAction order_update_action;
    MdEntryTypeDailyStatistics md_entry_type_daily_statistics;
    MdEntryPx md_entry_px;
    OpenCloseSettlFlag open_close_settl_flag;
    MdEntryTypeStatistics md_entry_type_statistics;
    MdEntrySize md_entry_size;
    TradeId trade_id;
    AggressorSide aggressor_side;
    LastMsgSeqNumProcessed last_msg_seq_num_processed;
    TotNumReports tot_num_reports;
    MdPriceLevelOptional md_price_level_optional;
    MdEntryType md_entry_type_;
    QuoteReqId quote_req_id;
    OrderQty order_qty;
    QuoteType quote_type;
    Side side;
    PutOrCall put_or_call;
    StrikePrice strike_price;
    StrikeCurrency strike_currency;
    MinCabPrice min_cab_price;
    MinPriceIncrementOptional min_price_increment_optional;
    UnderlyingSecurityId underlying_security_id;
    UnderlyingSymbol underlying_symbol;
    RelatedSecurityId related_security_id;
    RelatedSymbol related_symbol;
    MdTradeEntryId md_trade_entry_id;
    LastQty last_qty;
    OrderIdOptional order_id_optional;
    NoChunks no_chunks;
    CurrentChunk current_chunk;
    MdDisplayQty md_display_qty;
    ChannelResetGroup channel_reset_group;
    MDInstrumentDefinitionFuture27NoEventsGroup m_d_instrument_definition_future_27_no_events_group;
    MDInstrumentDefinitionFuture27NoMDFeedTypesGroup m_d_instrument_definition_future_27_no_m_d_feed_types_group;
    MDInstrumentDefinitionFuture27NoInstAttribGroup m_d_instrument_definition_future_27_no_inst_attrib_group;
    MDInstrumentDefinitionFuture27NoLotTypeRulesGroup m_d_instrument_definition_future_27_no_lot_type_rules_group;
    MDInstrumentDefinitionSpread29NoEventsGroup m_d_instrument_definition_spread_29_no_events_group;
    MDInstrumentDefinitionSpread29NoMDFeedTypesGroup m_d_instrument_definition_spread_29_no_m_d_feed_types_group;
    MDInstrumentDefinitionSpread29NoInstAttribGroup m_d_instrument_definition_spread_29_no_inst_attrib_group;
    MDInstrumentDefinitionSpread29NoLotTypeRulesGroup m_d_instrument_definition_spread_29_no_lot_type_rules_group;
    MDInstrumentDefinitionSpread29NoLegsGroup m_d_instrument_definition_spread_29_no_legs_group;
    MDIncrementalRefreshBook32NoMDEntriesGroup m_d_incremental_refresh_book_32_no_m_d_entries_group;
    MDIncrementalRefreshBook32NoOrderIDEntriesGroup m_d_incremental_refresh_book_32_no_order_i_d_entries_group;
    MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group;
    MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group;
    MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group;
    MDIncrementalRefreshTrade36NoMDEntriesGroup m_d_incremental_refresh_trade_36_no_m_d_entries_group;
    IncrementalRefreshVolumeGroup incremental_refresh_volume_group;
    SnapshotFullRefresh38NoMDEntriesGroup snapshot_full_refresh_38_no_m_d_entries_group;
    RelatedSymGroup related_sym_group;
    MDInstrumentDefinitionOption41NoEventsGroup m_d_instrument_definition_option_41_no_events_group;
    MDInstrumentDefinitionOption41NoMDFeedTypesGroup m_d_instrument_definition_option_41_no_m_d_feed_types_group;
    MDInstrumentDefinitionOption41NoInstAttribGroup m_d_instrument_definition_option_41_no_inst_attrib_group;
    MDInstrumentDefinitionOption41NoLotTypeRulesGroup m_d_instrument_definition_option_41_no_lot_type_rules_group;
    MDInstrumentDefinitionOption41NoUnderlyingsGroup m_d_instrument_definition_option_41_no_underlyings_group;
    MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup m_d_instrument_definition_option_41_no_related_instruments_group;
    MDIncrementalRefreshTradeSummary42NoMDEntriesGroup m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group;
    MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group;
    MDIncrementalRefreshOrderBook43NoMDEntriesGroup m_d_incremental_refresh_order_book_43_no_m_d_entries_group;
    SnapshotFullRefreshOrderBook44NoMDEntriesGroup snapshot_full_refresh_order_book_44_no_m_d_entries_group;

    ArrowRecord() = default;

    // parquet record reset
    void reset() {
        event_type.reset();
        transact_time.reset();
        block_length.reset();
        num_in_group.reset();
        appl_id.reset();
        heart_bt_int.reset();
        text.reset();
        tot_num_reports_optional.reset();
        security_update_action.reset();
        last_update_time.reset();
        md_security_trading_status.reset();
        market_segment_id.reset();
        underlying_product.reset();
        security_exchange.reset();
        security_group.reset();
        asset.reset();
        symbol.reset();
        security_id.reset();
        security_type.reset();
        cfi_code.reset();
        year.reset();
        month.reset();
        day.reset();
        week.reset();
        currency.reset();
        settl_currency.reset();
        match_algorithm.reset();
        min_trade_vol.reset();
        max_trade_vol.reset();
        min_price_increment.reset();
        display_factor.reset();
        main_fraction.reset();
        sub_fraction.reset();
        price_display_format.reset();
        unit_of_measure.reset();
        unit_of_measure_qty.reset();
        trading_reference_price.reset();
        open_interest_qty.reset();
        cleared_volume.reset();
        high_limit_price.reset();
        low_limit_price.reset();
        max_price_variation.reset();
        decay_quantity.reset();
        decay_start_date.reset();
        original_contract_size.reset();
        contract_multiplier.reset();
        contract_multiplier_unit.reset();
        flow_schedule_type.reset();
        min_price_increment_amount.reset();
        user_defined_instrument.reset();
        trading_reference_date.reset();
        event_time.reset();
        md_feed_type.reset();
        market_depth.reset();
        lot_type.reset();
        min_lot_size.reset();
        underlying_product_optional.reset();
        security_sub_type.reset();
        price_ratio.reset();
        tick_rule.reset();
        leg_security_id.reset();
        leg_side.reset();
        leg_ratio_qty.reset();
        leg_price.reset();
        leg_option_delta.reset();
        security_id_optional.reset();
        trade_date.reset();
        security_trading_status.reset();
        halt_reason.reset();
        security_trading_event.reset();
        md_entry_px_optional.reset();
        md_entry_size_optional.reset();
        rpt_seq.reset();
        number_of_orders.reset();
        md_price_level.reset();
        md_update_action.reset();
        md_entry_type_book.reset();
        order_id.reset();
        md_order_priority.reset();
        md_display_qty_optional.reset();
        reference_id.reset();
        order_update_action.reset();
        md_entry_type_daily_statistics.reset();
        md_entry_px.reset();
        open_close_settl_flag.reset();
        md_entry_type_statistics.reset();
        md_entry_size.reset();
        trade_id.reset();
        aggressor_side.reset();
        last_msg_seq_num_processed.reset();
        tot_num_reports.reset();
        md_price_level_optional.reset();
        md_entry_type_.reset();
        quote_req_id.reset();
        order_qty.reset();
        quote_type.reset();
        side.reset();
        put_or_call.reset();
        strike_price.reset();
        strike_currency.reset();
        min_cab_price.reset();
        min_price_increment_optional.reset();
        underlying_security_id.reset();
        underlying_symbol.reset();
        related_security_id.reset();
        related_symbol.reset();
        md_trade_entry_id.reset();
        last_qty.reset();
        order_id_optional.reset();
        no_chunks.reset();
        current_chunk.reset();
        md_display_qty.reset();
        channel_reset_group.reset();
        m_d_instrument_definition_future_27_no_events_group.reset();
        m_d_instrument_definition_future_27_no_m_d_feed_types_group.reset();
        m_d_instrument_definition_future_27_no_inst_attrib_group.reset();
        m_d_instrument_definition_future_27_no_lot_type_rules_group.reset();
        m_d_instrument_definition_spread_29_no_events_group.reset();
        m_d_instrument_definition_spread_29_no_m_d_feed_types_group.reset();
        m_d_instrument_definition_spread_29_no_inst_attrib_group.reset();
        m_d_instrument_definition_spread_29_no_lot_type_rules_group.reset();
        m_d_instrument_definition_spread_29_no_legs_group.reset();
        m_d_incremental_refresh_book_32_no_m_d_entries_group.reset();
        m_d_incremental_refresh_book_32_no_order_i_d_entries_group.reset();
        m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group.reset();
        m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group.reset();
        m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group.reset();
        m_d_incremental_refresh_trade_36_no_m_d_entries_group.reset();
        incremental_refresh_volume_group.reset();
        snapshot_full_refresh_38_no_m_d_entries_group.reset();
        related_sym_group.reset();
        m_d_instrument_definition_option_41_no_events_group.reset();
        m_d_instrument_definition_option_41_no_m_d_feed_types_group.reset();
        m_d_instrument_definition_option_41_no_inst_attrib_group.reset();
        m_d_instrument_definition_option_41_no_lot_type_rules_group.reset();
        m_d_instrument_definition_option_41_no_underlyings_group.reset();
        m_d_instrument_definition_option_41_no_related_instruments_group.reset();
        m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group.reset();
        m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group.reset();
        m_d_incremental_refresh_order_book_43_no_m_d_entries_group.reset();
        snapshot_full_refresh_order_book_44_no_m_d_entries_group.reset();
    }

    // arrow schema
    static auto schema() {
        return arrow::schema( {
            EventType::column(),
            TransactTime::column(),
            BlockLength::column(),
            NumInGroup::column(),
            ApplId::column(),
            HeartBtInt::column(),
            Text::column(),
            TotNumReportsOptional::column(),
            SecurityUpdateAction::column(),
            LastUpdateTime::column(),
            MdSecurityTradingStatus::column(),
            MarketSegmentId::column(),
            UnderlyingProduct::column(),
            SecurityExchange::column(),
            SecurityGroup::column(),
            Asset::column(),
            Symbol::column(),
            SecurityId::column(),
            SecurityType::column(),
            CfiCode::column(),
            Year::column(),
            Month::column(),
            Day::column(),
            Week::column(),
            Currency::column(),
            SettlCurrency::column(),
            MatchAlgorithm::column(),
            MinTradeVol::column(),
            MaxTradeVol::column(),
            MinPriceIncrement::column(),
            DisplayFactor::column(),
            MainFraction::column(),
            SubFraction::column(),
            PriceDisplayFormat::column(),
            UnitOfMeasure::column(),
            UnitOfMeasureQty::column(),
            TradingReferencePrice::column(),
            OpenInterestQty::column(),
            ClearedVolume::column(),
            HighLimitPrice::column(),
            LowLimitPrice::column(),
            MaxPriceVariation::column(),
            DecayQuantity::column(),
            DecayStartDate::column(),
            OriginalContractSize::column(),
            ContractMultiplier::column(),
            ContractMultiplierUnit::column(),
            FlowScheduleType::column(),
            MinPriceIncrementAmount::column(),
            UserDefinedInstrument::column(),
            TradingReferenceDate::column(),
            EventTime::column(),
            MdFeedType::column(),
            MarketDepth::column(),
            LotType::column(),
            MinLotSize::column(),
            UnderlyingProductOptional::column(),
            SecuritySubType::column(),
            PriceRatio::column(),
            TickRule::column(),
            LegSecurityId::column(),
            LegSide::column(),
            LegRatioQty::column(),
            LegPrice::column(),
            LegOptionDelta::column(),
            SecurityIdOptional::column(),
            TradeDate::column(),
            SecurityTradingStatus::column(),
            HaltReason::column(),
            SecurityTradingEvent::column(),
            MdEntryPxOptional::column(),
            MdEntrySizeOptional::column(),
            RptSeq::column(),
            NumberOfOrders::column(),
            MdPriceLevel::column(),
            MdUpdateAction::column(),
            MdEntryTypeBook::column(),
            OrderId::column(),
            MdOrderPriority::column(),
            MdDisplayQtyOptional::column(),
            ReferenceId::column(),
            OrderUpdateAction::column(),
            MdEntryTypeDailyStatistics::column(),
            MdEntryPx::column(),
            OpenCloseSettlFlag::column(),
            MdEntryTypeStatistics::column(),
            MdEntrySize::column(),
            TradeId::column(),
            AggressorSide::column(),
            LastMsgSeqNumProcessed::column(),
            TotNumReports::column(),
            MdPriceLevelOptional::column(),
            MdEntryType::column(),
            QuoteReqId::column(),
            OrderQty::column(),
            QuoteType::column(),
            Side::column(),
            PutOrCall::column(),
            StrikePrice::column(),
            StrikeCurrency::column(),
            MinCabPrice::column(),
            MinPriceIncrementOptional::column(),
            UnderlyingSecurityId::column(),
            UnderlyingSymbol::column(),
            RelatedSecurityId::column(),
            RelatedSymbol::column(),
            MdTradeEntryId::column(),
            LastQty::column(),
            OrderIdOptional::column(),
            NoChunks::column(),
            CurrentChunk::column(),
            MdDisplayQty::column(),
            ChannelResetGroup::column(),
            MDInstrumentDefinitionFuture27NoEventsGroup::column(),
            MDInstrumentDefinitionFuture27NoMDFeedTypesGroup::column(),
            MDInstrumentDefinitionFuture27NoInstAttribGroup::column(),
            MDInstrumentDefinitionFuture27NoLotTypeRulesGroup::column(),
            MDInstrumentDefinitionSpread29NoEventsGroup::column(),
            MDInstrumentDefinitionSpread29NoMDFeedTypesGroup::column(),
            MDInstrumentDefinitionSpread29NoInstAttribGroup::column(),
            MDInstrumentDefinitionSpread29NoLotTypeRulesGroup::column(),
            MDInstrumentDefinitionSpread29NoLegsGroup::column(),
            MDIncrementalRefreshBook32NoMDEntriesGroup::column(),
            MDIncrementalRefreshBook32NoOrderIDEntriesGroup::column(),
            MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup::column(),
            MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup::column(),
            MDIncrementalRefreshSessionStatistics35NoMDEntriesGroup::column(),
            MDIncrementalRefreshTrade36NoMDEntriesGroup::column(),
            IncrementalRefreshVolumeGroup::column(),
            SnapshotFullRefresh38NoMDEntriesGroup::column(),
            RelatedSymGroup::column(),
            MDInstrumentDefinitionOption41NoEventsGroup::column(),
            MDInstrumentDefinitionOption41NoMDFeedTypesGroup::column(),
            MDInstrumentDefinitionOption41NoInstAttribGroup::column(),
            MDInstrumentDefinitionOption41NoLotTypeRulesGroup::column(),
            MDInstrumentDefinitionOption41NoUnderlyingsGroup::column(),
            MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup::column(),
            MDIncrementalRefreshTradeSummary42NoMDEntriesGroup::column(),
            MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup::column(),
            MDIncrementalRefreshOrderBook43NoMDEntriesGroup::column(),
            SnapshotFullRefreshOrderBook44NoMDEntriesGroup::column()
        } );
    }
};
}
