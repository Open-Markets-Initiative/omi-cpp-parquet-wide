#pragma once

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/util/byte_size.h>
#include <parquet/arrow/writer.h>

#include "Record.hpp"

namespace cme {
struct ArrowBatch {

    ArrowBatch(std::shared_ptr<arrow::Schema> schema, const parquet::Options& options)
        : schema(std::move(schema)),
          max_rows(options.max_row_group_size),
          output_path(options.file),
          options(options)
    {
        OpenOutput();
    }

    // batch writer
    arrow::Status write(const ArrowRecord& record) {
        if (!writer) {
            OpenOutput();
        }
        ARROW_RETURN_NOT_OK(record.event_type.append(*event_type_builder));
        ARROW_RETURN_NOT_OK(record.packet_sequence_number.append(*packet_sequence_number_builder));
        ARROW_RETURN_NOT_OK(record.sending_time.append(*sending_time_builder));
        ARROW_RETURN_NOT_OK(record.transact_time.append(*transact_time_builder));
        ARROW_RETURN_NOT_OK(record.block_length.append(*block_length_builder));
        ARROW_RETURN_NOT_OK(record.num_in_group.append(*num_in_group_builder));
        ARROW_RETURN_NOT_OK(record.channel_reset_group.append(*channel_reset_group_builder));
        ARROW_RETURN_NOT_OK(record.heart_bt_int.append(*heart_bt_int_builder));
        ARROW_RETURN_NOT_OK(record.text.append(*text_builder));
        ARROW_RETURN_NOT_OK(record.tot_num_reports_optional.append(*tot_num_reports_optional_builder));
        ARROW_RETURN_NOT_OK(record.security_update_action.append(*security_update_action_builder));
        ARROW_RETURN_NOT_OK(record.last_update_time.append(*last_update_time_builder));
        ARROW_RETURN_NOT_OK(record.md_security_trading_status.append(*md_security_trading_status_builder));
        ARROW_RETURN_NOT_OK(record.appl_id.append(*appl_id_builder));
        ARROW_RETURN_NOT_OK(record.market_segment_id.append(*market_segment_id_builder));
        ARROW_RETURN_NOT_OK(record.underlying_product.append(*underlying_product_builder));
        ARROW_RETURN_NOT_OK(record.security_exchange.append(*security_exchange_builder));
        ARROW_RETURN_NOT_OK(record.security_group.append(*security_group_builder));
        ARROW_RETURN_NOT_OK(record.asset.append(*asset_builder));
        ARROW_RETURN_NOT_OK(record.symbol.append(*symbol_builder));
        ARROW_RETURN_NOT_OK(record.security_id.append(*security_id_builder));
        ARROW_RETURN_NOT_OK(record.security_type.append(*security_type_builder));
        ARROW_RETURN_NOT_OK(record.cfi_code.append(*cfi_code_builder));
        ARROW_RETURN_NOT_OK(record.year.append(*year_builder));
        ARROW_RETURN_NOT_OK(record.month.append(*month_builder));
        ARROW_RETURN_NOT_OK(record.day.append(*day_builder));
        ARROW_RETURN_NOT_OK(record.week.append(*week_builder));
        ARROW_RETURN_NOT_OK(record.currency.append(*currency_builder));
        ARROW_RETURN_NOT_OK(record.settl_currency.append(*settl_currency_builder));
        ARROW_RETURN_NOT_OK(record.match_algorithm.append(*match_algorithm_builder));
        ARROW_RETURN_NOT_OK(record.min_trade_vol.append(*min_trade_vol_builder));
        ARROW_RETURN_NOT_OK(record.max_trade_vol.append(*max_trade_vol_builder));
        ARROW_RETURN_NOT_OK(record.min_price_increment.append(*min_price_increment_builder));
        ARROW_RETURN_NOT_OK(record.display_factor.append(*display_factor_builder));
        ARROW_RETURN_NOT_OK(record.main_fraction.append(*main_fraction_builder));
        ARROW_RETURN_NOT_OK(record.sub_fraction.append(*sub_fraction_builder));
        ARROW_RETURN_NOT_OK(record.price_display_format.append(*price_display_format_builder));
        ARROW_RETURN_NOT_OK(record.unit_of_measure.append(*unit_of_measure_builder));
        ARROW_RETURN_NOT_OK(record.unit_of_measure_qty.append(*unit_of_measure_qty_builder));
        ARROW_RETURN_NOT_OK(record.trading_reference_price.append(*trading_reference_price_builder));
        ARROW_RETURN_NOT_OK(record.open_interest_qty.append(*open_interest_qty_builder));
        ARROW_RETURN_NOT_OK(record.cleared_volume.append(*cleared_volume_builder));
        ARROW_RETURN_NOT_OK(record.high_limit_price.append(*high_limit_price_builder));
        ARROW_RETURN_NOT_OK(record.low_limit_price.append(*low_limit_price_builder));
        ARROW_RETURN_NOT_OK(record.max_price_variation.append(*max_price_variation_builder));
        ARROW_RETURN_NOT_OK(record.decay_quantity.append(*decay_quantity_builder));
        ARROW_RETURN_NOT_OK(record.decay_start_date.append(*decay_start_date_builder));
        ARROW_RETURN_NOT_OK(record.original_contract_size.append(*original_contract_size_builder));
        ARROW_RETURN_NOT_OK(record.contract_multiplier.append(*contract_multiplier_builder));
        ARROW_RETURN_NOT_OK(record.contract_multiplier_unit.append(*contract_multiplier_unit_builder));
        ARROW_RETURN_NOT_OK(record.flow_schedule_type.append(*flow_schedule_type_builder));
        ARROW_RETURN_NOT_OK(record.min_price_increment_amount.append(*min_price_increment_amount_builder));
        ARROW_RETURN_NOT_OK(record.user_defined_instrument.append(*user_defined_instrument_builder));
        ARROW_RETURN_NOT_OK(record.trading_reference_date.append(*trading_reference_date_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_future_27_no_events_group.append(*m_d_instrument_definition_future_27_no_events_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_future_27_no_m_d_feed_types_group.append(*m_d_instrument_definition_future_27_no_m_d_feed_types_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_future_27_no_inst_attrib_group.append(*m_d_instrument_definition_future_27_no_inst_attrib_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_future_27_no_lot_type_rules_group.append(*m_d_instrument_definition_future_27_no_lot_type_rules_group_builder));
        ARROW_RETURN_NOT_OK(record.underlying_product_optional.append(*underlying_product_optional_builder));
        ARROW_RETURN_NOT_OK(record.security_sub_type.append(*security_sub_type_builder));
        ARROW_RETURN_NOT_OK(record.price_ratio.append(*price_ratio_builder));
        ARROW_RETURN_NOT_OK(record.tick_rule.append(*tick_rule_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_spread_29_no_events_group.append(*m_d_instrument_definition_spread_29_no_events_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_spread_29_no_m_d_feed_types_group.append(*m_d_instrument_definition_spread_29_no_m_d_feed_types_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_spread_29_no_inst_attrib_group.append(*m_d_instrument_definition_spread_29_no_inst_attrib_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_spread_29_no_lot_type_rules_group.append(*m_d_instrument_definition_spread_29_no_lot_type_rules_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_spread_29_no_legs_group.append(*m_d_instrument_definition_spread_29_no_legs_group_builder));
        ARROW_RETURN_NOT_OK(record.security_id_optional.append(*security_id_optional_builder));
        ARROW_RETURN_NOT_OK(record.trade_date.append(*trade_date_builder));
        ARROW_RETURN_NOT_OK(record.security_trading_status.append(*security_trading_status_builder));
        ARROW_RETURN_NOT_OK(record.halt_reason.append(*halt_reason_builder));
        ARROW_RETURN_NOT_OK(record.security_trading_event.append(*security_trading_event_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_book_32_no_m_d_entries_group.append(*m_d_incremental_refresh_book_32_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_book_32_no_order_i_d_entries_group.append(*m_d_incremental_refresh_book_32_no_order_i_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group.append(*m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group.append(*m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group.append(*m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_trade_36_no_m_d_entries_group.append(*m_d_incremental_refresh_trade_36_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.incremental_refresh_volume_group.append(*incremental_refresh_volume_group_builder));
        ARROW_RETURN_NOT_OK(record.last_msg_seq_num_processed.append(*last_msg_seq_num_processed_builder));
        ARROW_RETURN_NOT_OK(record.tot_num_reports.append(*tot_num_reports_builder));
        ARROW_RETURN_NOT_OK(record.rpt_seq.append(*rpt_seq_builder));
        ARROW_RETURN_NOT_OK(record.snapshot_full_refresh_38_no_m_d_entries_group.append(*snapshot_full_refresh_38_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.quote_req_id.append(*quote_req_id_builder));
        ARROW_RETURN_NOT_OK(record.related_sym_group.append(*related_sym_group_builder));
        ARROW_RETURN_NOT_OK(record.put_or_call.append(*put_or_call_builder));
        ARROW_RETURN_NOT_OK(record.strike_price.append(*strike_price_builder));
        ARROW_RETURN_NOT_OK(record.strike_currency.append(*strike_currency_builder));
        ARROW_RETURN_NOT_OK(record.min_cab_price.append(*min_cab_price_builder));
        ARROW_RETURN_NOT_OK(record.min_price_increment_optional.append(*min_price_increment_optional_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_option_41_no_events_group.append(*m_d_instrument_definition_option_41_no_events_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_option_41_no_m_d_feed_types_group.append(*m_d_instrument_definition_option_41_no_m_d_feed_types_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_option_41_no_inst_attrib_group.append(*m_d_instrument_definition_option_41_no_inst_attrib_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_option_41_no_lot_type_rules_group.append(*m_d_instrument_definition_option_41_no_lot_type_rules_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_option_41_no_underlyings_group.append(*m_d_instrument_definition_option_41_no_underlyings_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_instrument_definition_option_41_no_related_instruments_group.append(*m_d_instrument_definition_option_41_no_related_instruments_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group.append(*m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group.append(*m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.m_d_incremental_refresh_order_book_43_no_m_d_entries_group.append(*m_d_incremental_refresh_order_book_43_no_m_d_entries_group_builder));
        ARROW_RETURN_NOT_OK(record.no_chunks.append(*no_chunks_builder));
        ARROW_RETURN_NOT_OK(record.current_chunk.append(*current_chunk_builder));
        ARROW_RETURN_NOT_OK(record.snapshot_full_refresh_order_book_44_no_m_d_entries_group.append(*snapshot_full_refresh_order_book_44_no_m_d_entries_group_builder));

        row_count++;

        if (row_count >= max_rows) {
            return flush();
        }

        return arrow::Status::OK();
    }

    // flush batch
    arrow::Status flush() {
        if (row_count == 0) {
            return arrow::Status::OK();
        }

        std::shared_ptr<arrow::Array> event_type_column;
        std::shared_ptr<arrow::Array> packet_sequence_number_column;
        std::shared_ptr<arrow::Array> sending_time_column;
        std::shared_ptr<arrow::Array> transact_time_column;
        std::shared_ptr<arrow::Array> block_length_column;
        std::shared_ptr<arrow::Array> num_in_group_column;
        std::shared_ptr<arrow::Array> channel_reset_group_column;
        std::shared_ptr<arrow::Array> heart_bt_int_column;
        std::shared_ptr<arrow::Array> text_column;
        std::shared_ptr<arrow::Array> tot_num_reports_optional_column;
        std::shared_ptr<arrow::Array> security_update_action_column;
        std::shared_ptr<arrow::Array> last_update_time_column;
        std::shared_ptr<arrow::Array> md_security_trading_status_column;
        std::shared_ptr<arrow::Array> appl_id_column;
        std::shared_ptr<arrow::Array> market_segment_id_column;
        std::shared_ptr<arrow::Array> underlying_product_column;
        std::shared_ptr<arrow::Array> security_exchange_column;
        std::shared_ptr<arrow::Array> security_group_column;
        std::shared_ptr<arrow::Array> asset_column;
        std::shared_ptr<arrow::Array> symbol_column;
        std::shared_ptr<arrow::Array> security_id_column;
        std::shared_ptr<arrow::Array> security_type_column;
        std::shared_ptr<arrow::Array> cfi_code_column;
        std::shared_ptr<arrow::Array> year_column;
        std::shared_ptr<arrow::Array> month_column;
        std::shared_ptr<arrow::Array> day_column;
        std::shared_ptr<arrow::Array> week_column;
        std::shared_ptr<arrow::Array> currency_column;
        std::shared_ptr<arrow::Array> settl_currency_column;
        std::shared_ptr<arrow::Array> match_algorithm_column;
        std::shared_ptr<arrow::Array> min_trade_vol_column;
        std::shared_ptr<arrow::Array> max_trade_vol_column;
        std::shared_ptr<arrow::Array> min_price_increment_column;
        std::shared_ptr<arrow::Array> display_factor_column;
        std::shared_ptr<arrow::Array> main_fraction_column;
        std::shared_ptr<arrow::Array> sub_fraction_column;
        std::shared_ptr<arrow::Array> price_display_format_column;
        std::shared_ptr<arrow::Array> unit_of_measure_column;
        std::shared_ptr<arrow::Array> unit_of_measure_qty_column;
        std::shared_ptr<arrow::Array> trading_reference_price_column;
        std::shared_ptr<arrow::Array> open_interest_qty_column;
        std::shared_ptr<arrow::Array> cleared_volume_column;
        std::shared_ptr<arrow::Array> high_limit_price_column;
        std::shared_ptr<arrow::Array> low_limit_price_column;
        std::shared_ptr<arrow::Array> max_price_variation_column;
        std::shared_ptr<arrow::Array> decay_quantity_column;
        std::shared_ptr<arrow::Array> decay_start_date_column;
        std::shared_ptr<arrow::Array> original_contract_size_column;
        std::shared_ptr<arrow::Array> contract_multiplier_column;
        std::shared_ptr<arrow::Array> contract_multiplier_unit_column;
        std::shared_ptr<arrow::Array> flow_schedule_type_column;
        std::shared_ptr<arrow::Array> min_price_increment_amount_column;
        std::shared_ptr<arrow::Array> user_defined_instrument_column;
        std::shared_ptr<arrow::Array> trading_reference_date_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_future_27_no_events_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_future_27_no_m_d_feed_types_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_future_27_no_inst_attrib_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_future_27_no_lot_type_rules_group_column;
        std::shared_ptr<arrow::Array> underlying_product_optional_column;
        std::shared_ptr<arrow::Array> security_sub_type_column;
        std::shared_ptr<arrow::Array> price_ratio_column;
        std::shared_ptr<arrow::Array> tick_rule_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_spread_29_no_events_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_spread_29_no_m_d_feed_types_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_spread_29_no_inst_attrib_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_spread_29_no_lot_type_rules_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_spread_29_no_legs_group_column;
        std::shared_ptr<arrow::Array> security_id_optional_column;
        std::shared_ptr<arrow::Array> trade_date_column;
        std::shared_ptr<arrow::Array> security_trading_status_column;
        std::shared_ptr<arrow::Array> halt_reason_column;
        std::shared_ptr<arrow::Array> security_trading_event_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_book_32_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_book_32_no_order_i_d_entries_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_trade_36_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> incremental_refresh_volume_group_column;
        std::shared_ptr<arrow::Array> last_msg_seq_num_processed_column;
        std::shared_ptr<arrow::Array> tot_num_reports_column;
        std::shared_ptr<arrow::Array> rpt_seq_column;
        std::shared_ptr<arrow::Array> snapshot_full_refresh_38_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> quote_req_id_column;
        std::shared_ptr<arrow::Array> related_sym_group_column;
        std::shared_ptr<arrow::Array> put_or_call_column;
        std::shared_ptr<arrow::Array> strike_price_column;
        std::shared_ptr<arrow::Array> strike_currency_column;
        std::shared_ptr<arrow::Array> min_cab_price_column;
        std::shared_ptr<arrow::Array> min_price_increment_optional_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_option_41_no_events_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_option_41_no_m_d_feed_types_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_option_41_no_inst_attrib_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_option_41_no_lot_type_rules_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_option_41_no_underlyings_group_column;
        std::shared_ptr<arrow::Array> m_d_instrument_definition_option_41_no_related_instruments_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_column;
        std::shared_ptr<arrow::Array> m_d_incremental_refresh_order_book_43_no_m_d_entries_group_column;
        std::shared_ptr<arrow::Array> no_chunks_column;
        std::shared_ptr<arrow::Array> current_chunk_column;
        std::shared_ptr<arrow::Array> snapshot_full_refresh_order_book_44_no_m_d_entries_group_column;

        ARROW_RETURN_NOT_OK(event_type_builder->Finish(&event_type_column));
        ARROW_RETURN_NOT_OK(packet_sequence_number_builder->Finish(&packet_sequence_number_column));
        ARROW_RETURN_NOT_OK(sending_time_builder->Finish(&sending_time_column));
        ARROW_RETURN_NOT_OK(transact_time_builder->Finish(&transact_time_column));
        ARROW_RETURN_NOT_OK(block_length_builder->Finish(&block_length_column));
        ARROW_RETURN_NOT_OK(num_in_group_builder->Finish(&num_in_group_column));
        ARROW_RETURN_NOT_OK(channel_reset_group_builder->Finish(&channel_reset_group_column));
        ARROW_RETURN_NOT_OK(heart_bt_int_builder->Finish(&heart_bt_int_column));
        ARROW_RETURN_NOT_OK(text_builder->Finish(&text_column));
        ARROW_RETURN_NOT_OK(tot_num_reports_optional_builder->Finish(&tot_num_reports_optional_column));
        ARROW_RETURN_NOT_OK(security_update_action_builder->Finish(&security_update_action_column));
        ARROW_RETURN_NOT_OK(last_update_time_builder->Finish(&last_update_time_column));
        ARROW_RETURN_NOT_OK(md_security_trading_status_builder->Finish(&md_security_trading_status_column));
        ARROW_RETURN_NOT_OK(appl_id_builder->Finish(&appl_id_column));
        ARROW_RETURN_NOT_OK(market_segment_id_builder->Finish(&market_segment_id_column));
        ARROW_RETURN_NOT_OK(underlying_product_builder->Finish(&underlying_product_column));
        ARROW_RETURN_NOT_OK(security_exchange_builder->Finish(&security_exchange_column));
        ARROW_RETURN_NOT_OK(security_group_builder->Finish(&security_group_column));
        ARROW_RETURN_NOT_OK(asset_builder->Finish(&asset_column));
        ARROW_RETURN_NOT_OK(symbol_builder->Finish(&symbol_column));
        ARROW_RETURN_NOT_OK(security_id_builder->Finish(&security_id_column));
        ARROW_RETURN_NOT_OK(security_type_builder->Finish(&security_type_column));
        ARROW_RETURN_NOT_OK(cfi_code_builder->Finish(&cfi_code_column));
        ARROW_RETURN_NOT_OK(year_builder->Finish(&year_column));
        ARROW_RETURN_NOT_OK(month_builder->Finish(&month_column));
        ARROW_RETURN_NOT_OK(day_builder->Finish(&day_column));
        ARROW_RETURN_NOT_OK(week_builder->Finish(&week_column));
        ARROW_RETURN_NOT_OK(currency_builder->Finish(&currency_column));
        ARROW_RETURN_NOT_OK(settl_currency_builder->Finish(&settl_currency_column));
        ARROW_RETURN_NOT_OK(match_algorithm_builder->Finish(&match_algorithm_column));
        ARROW_RETURN_NOT_OK(min_trade_vol_builder->Finish(&min_trade_vol_column));
        ARROW_RETURN_NOT_OK(max_trade_vol_builder->Finish(&max_trade_vol_column));
        ARROW_RETURN_NOT_OK(min_price_increment_builder->Finish(&min_price_increment_column));
        ARROW_RETURN_NOT_OK(display_factor_builder->Finish(&display_factor_column));
        ARROW_RETURN_NOT_OK(main_fraction_builder->Finish(&main_fraction_column));
        ARROW_RETURN_NOT_OK(sub_fraction_builder->Finish(&sub_fraction_column));
        ARROW_RETURN_NOT_OK(price_display_format_builder->Finish(&price_display_format_column));
        ARROW_RETURN_NOT_OK(unit_of_measure_builder->Finish(&unit_of_measure_column));
        ARROW_RETURN_NOT_OK(unit_of_measure_qty_builder->Finish(&unit_of_measure_qty_column));
        ARROW_RETURN_NOT_OK(trading_reference_price_builder->Finish(&trading_reference_price_column));
        ARROW_RETURN_NOT_OK(open_interest_qty_builder->Finish(&open_interest_qty_column));
        ARROW_RETURN_NOT_OK(cleared_volume_builder->Finish(&cleared_volume_column));
        ARROW_RETURN_NOT_OK(high_limit_price_builder->Finish(&high_limit_price_column));
        ARROW_RETURN_NOT_OK(low_limit_price_builder->Finish(&low_limit_price_column));
        ARROW_RETURN_NOT_OK(max_price_variation_builder->Finish(&max_price_variation_column));
        ARROW_RETURN_NOT_OK(decay_quantity_builder->Finish(&decay_quantity_column));
        ARROW_RETURN_NOT_OK(decay_start_date_builder->Finish(&decay_start_date_column));
        ARROW_RETURN_NOT_OK(original_contract_size_builder->Finish(&original_contract_size_column));
        ARROW_RETURN_NOT_OK(contract_multiplier_builder->Finish(&contract_multiplier_column));
        ARROW_RETURN_NOT_OK(contract_multiplier_unit_builder->Finish(&contract_multiplier_unit_column));
        ARROW_RETURN_NOT_OK(flow_schedule_type_builder->Finish(&flow_schedule_type_column));
        ARROW_RETURN_NOT_OK(min_price_increment_amount_builder->Finish(&min_price_increment_amount_column));
        ARROW_RETURN_NOT_OK(user_defined_instrument_builder->Finish(&user_defined_instrument_column));
        ARROW_RETURN_NOT_OK(trading_reference_date_builder->Finish(&trading_reference_date_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_future_27_no_events_group_builder->Finish(&m_d_instrument_definition_future_27_no_events_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_future_27_no_m_d_feed_types_group_builder->Finish(&m_d_instrument_definition_future_27_no_m_d_feed_types_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_future_27_no_inst_attrib_group_builder->Finish(&m_d_instrument_definition_future_27_no_inst_attrib_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_future_27_no_lot_type_rules_group_builder->Finish(&m_d_instrument_definition_future_27_no_lot_type_rules_group_column));
        ARROW_RETURN_NOT_OK(underlying_product_optional_builder->Finish(&underlying_product_optional_column));
        ARROW_RETURN_NOT_OK(security_sub_type_builder->Finish(&security_sub_type_column));
        ARROW_RETURN_NOT_OK(price_ratio_builder->Finish(&price_ratio_column));
        ARROW_RETURN_NOT_OK(tick_rule_builder->Finish(&tick_rule_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_spread_29_no_events_group_builder->Finish(&m_d_instrument_definition_spread_29_no_events_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_spread_29_no_m_d_feed_types_group_builder->Finish(&m_d_instrument_definition_spread_29_no_m_d_feed_types_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_spread_29_no_inst_attrib_group_builder->Finish(&m_d_instrument_definition_spread_29_no_inst_attrib_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_spread_29_no_lot_type_rules_group_builder->Finish(&m_d_instrument_definition_spread_29_no_lot_type_rules_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_spread_29_no_legs_group_builder->Finish(&m_d_instrument_definition_spread_29_no_legs_group_column));
        ARROW_RETURN_NOT_OK(security_id_optional_builder->Finish(&security_id_optional_column));
        ARROW_RETURN_NOT_OK(trade_date_builder->Finish(&trade_date_column));
        ARROW_RETURN_NOT_OK(security_trading_status_builder->Finish(&security_trading_status_column));
        ARROW_RETURN_NOT_OK(halt_reason_builder->Finish(&halt_reason_column));
        ARROW_RETURN_NOT_OK(security_trading_event_builder->Finish(&security_trading_event_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_book_32_no_m_d_entries_group_builder->Finish(&m_d_incremental_refresh_book_32_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_book_32_no_order_i_d_entries_group_builder->Finish(&m_d_incremental_refresh_book_32_no_order_i_d_entries_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_builder->Finish(&m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_builder->Finish(&m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_builder->Finish(&m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_trade_36_no_m_d_entries_group_builder->Finish(&m_d_incremental_refresh_trade_36_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(incremental_refresh_volume_group_builder->Finish(&incremental_refresh_volume_group_column));
        ARROW_RETURN_NOT_OK(last_msg_seq_num_processed_builder->Finish(&last_msg_seq_num_processed_column));
        ARROW_RETURN_NOT_OK(tot_num_reports_builder->Finish(&tot_num_reports_column));
        ARROW_RETURN_NOT_OK(rpt_seq_builder->Finish(&rpt_seq_column));
        ARROW_RETURN_NOT_OK(snapshot_full_refresh_38_no_m_d_entries_group_builder->Finish(&snapshot_full_refresh_38_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(quote_req_id_builder->Finish(&quote_req_id_column));
        ARROW_RETURN_NOT_OK(related_sym_group_builder->Finish(&related_sym_group_column));
        ARROW_RETURN_NOT_OK(put_or_call_builder->Finish(&put_or_call_column));
        ARROW_RETURN_NOT_OK(strike_price_builder->Finish(&strike_price_column));
        ARROW_RETURN_NOT_OK(strike_currency_builder->Finish(&strike_currency_column));
        ARROW_RETURN_NOT_OK(min_cab_price_builder->Finish(&min_cab_price_column));
        ARROW_RETURN_NOT_OK(min_price_increment_optional_builder->Finish(&min_price_increment_optional_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_option_41_no_events_group_builder->Finish(&m_d_instrument_definition_option_41_no_events_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_option_41_no_m_d_feed_types_group_builder->Finish(&m_d_instrument_definition_option_41_no_m_d_feed_types_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_option_41_no_inst_attrib_group_builder->Finish(&m_d_instrument_definition_option_41_no_inst_attrib_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_option_41_no_lot_type_rules_group_builder->Finish(&m_d_instrument_definition_option_41_no_lot_type_rules_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_option_41_no_underlyings_group_builder->Finish(&m_d_instrument_definition_option_41_no_underlyings_group_column));
        ARROW_RETURN_NOT_OK(m_d_instrument_definition_option_41_no_related_instruments_group_builder->Finish(&m_d_instrument_definition_option_41_no_related_instruments_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_builder->Finish(&m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_builder->Finish(&m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_column));
        ARROW_RETURN_NOT_OK(m_d_incremental_refresh_order_book_43_no_m_d_entries_group_builder->Finish(&m_d_incremental_refresh_order_book_43_no_m_d_entries_group_column));
        ARROW_RETURN_NOT_OK(no_chunks_builder->Finish(&no_chunks_column));
        ARROW_RETURN_NOT_OK(current_chunk_builder->Finish(&current_chunk_column));
        ARROW_RETURN_NOT_OK(snapshot_full_refresh_order_book_44_no_m_d_entries_group_builder->Finish(&snapshot_full_refresh_order_book_44_no_m_d_entries_group_column));

        auto batch = arrow::RecordBatch::Make(schema, row_count, {
            event_type_column,
            packet_sequence_number_column,
            sending_time_column,
            transact_time_column,
            block_length_column,
            num_in_group_column,
            channel_reset_group_column,
            heart_bt_int_column,
            text_column,
            tot_num_reports_optional_column,
            security_update_action_column,
            last_update_time_column,
            md_security_trading_status_column,
            appl_id_column,
            market_segment_id_column,
            underlying_product_column,
            security_exchange_column,
            security_group_column,
            asset_column,
            symbol_column,
            security_id_column,
            security_type_column,
            cfi_code_column,
            year_column,
            month_column,
            day_column,
            week_column,
            currency_column,
            settl_currency_column,
            match_algorithm_column,
            min_trade_vol_column,
            max_trade_vol_column,
            min_price_increment_column,
            display_factor_column,
            main_fraction_column,
            sub_fraction_column,
            price_display_format_column,
            unit_of_measure_column,
            unit_of_measure_qty_column,
            trading_reference_price_column,
            open_interest_qty_column,
            cleared_volume_column,
            high_limit_price_column,
            low_limit_price_column,
            max_price_variation_column,
            decay_quantity_column,
            decay_start_date_column,
            original_contract_size_column,
            contract_multiplier_column,
            contract_multiplier_unit_column,
            flow_schedule_type_column,
            min_price_increment_amount_column,
            user_defined_instrument_column,
            trading_reference_date_column,
            m_d_instrument_definition_future_27_no_events_group_column,
            m_d_instrument_definition_future_27_no_m_d_feed_types_group_column,
            m_d_instrument_definition_future_27_no_inst_attrib_group_column,
            m_d_instrument_definition_future_27_no_lot_type_rules_group_column,
            underlying_product_optional_column,
            security_sub_type_column,
            price_ratio_column,
            tick_rule_column,
            m_d_instrument_definition_spread_29_no_events_group_column,
            m_d_instrument_definition_spread_29_no_m_d_feed_types_group_column,
            m_d_instrument_definition_spread_29_no_inst_attrib_group_column,
            m_d_instrument_definition_spread_29_no_lot_type_rules_group_column,
            m_d_instrument_definition_spread_29_no_legs_group_column,
            security_id_optional_column,
            trade_date_column,
            security_trading_status_column,
            halt_reason_column,
            security_trading_event_column,
            m_d_incremental_refresh_book_32_no_m_d_entries_group_column,
            m_d_incremental_refresh_book_32_no_order_i_d_entries_group_column,
            m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_column,
            m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_column,
            m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_column,
            m_d_incremental_refresh_trade_36_no_m_d_entries_group_column,
            incremental_refresh_volume_group_column,
            last_msg_seq_num_processed_column,
            tot_num_reports_column,
            rpt_seq_column,
            snapshot_full_refresh_38_no_m_d_entries_group_column,
            quote_req_id_column,
            related_sym_group_column,
            put_or_call_column,
            strike_price_column,
            strike_currency_column,
            min_cab_price_column,
            min_price_increment_optional_column,
            m_d_instrument_definition_option_41_no_events_group_column,
            m_d_instrument_definition_option_41_no_m_d_feed_types_group_column,
            m_d_instrument_definition_option_41_no_inst_attrib_group_column,
            m_d_instrument_definition_option_41_no_lot_type_rules_group_column,
            m_d_instrument_definition_option_41_no_underlyings_group_column,
            m_d_instrument_definition_option_41_no_related_instruments_group_column,
            m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_column,
            m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_column,
            m_d_incremental_refresh_order_book_43_no_m_d_entries_group_column,
            no_chunks_column,
            current_chunk_column,
            snapshot_full_refresh_order_book_44_no_m_d_entries_group_column,
        } );

        ARROW_RETURN_NOT_OK(writer->WriteRecordBatch(*batch));
        estimated_bytes += arrow::util::TotalBufferSize(*batch);

        // roll to next file if size limit exceeded
        if (options.max_file_size > 0 && estimated_bytes >= options.max_file_size) {
            ARROW_RETURN_NOT_OK(writer->Close());
            writer.reset();
            estimated_bytes = 0;
            file_index++;
            return arrow::Status::OK();
        }

        reset();

        return arrow::Status::OK();
    }

    // close file
    arrow::Status close() {
        ARROW_RETURN_NOT_OK(flush());
        if (writer) {
            return writer->Close();
        }
        return arrow::Status::OK();
    }
  protected:

    // reset arrow builders
    void reset() {
        event_type_builder = std::make_unique<arrow::StringBuilder>();
        packet_sequence_number_builder = std::make_unique<arrow::UInt32Builder>();
        sending_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        transact_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        block_length_builder = std::make_unique<arrow::UInt16Builder>();
        num_in_group_builder = std::make_unique<arrow::UInt8Builder>();
        channel_reset_group_builder = std::make_unique<arrow::StringBuilder>();
        heart_bt_int_builder = std::make_unique<arrow::Int8Builder>();
        text_builder = std::make_unique<arrow::StringBuilder>();
        tot_num_reports_optional_builder = std::make_unique<arrow::UInt32Builder>();
        security_update_action_builder = std::make_unique<arrow::StringBuilder>();
        last_update_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        md_security_trading_status_builder = std::make_unique<arrow::UInt8Builder>();
        appl_id_builder = std::make_unique<arrow::Int16Builder>();
        market_segment_id_builder = std::make_unique<arrow::UInt8Builder>();
        underlying_product_builder = std::make_unique<arrow::UInt8Builder>();
        security_exchange_builder = std::make_unique<arrow::StringBuilder>();
        security_group_builder = std::make_unique<arrow::StringBuilder>();
        asset_builder = std::make_unique<arrow::StringBuilder>();
        symbol_builder = std::make_unique<arrow::StringBuilder>();
        security_id_builder = std::make_unique<arrow::Int32Builder>();
        security_type_builder = std::make_unique<arrow::StringBuilder>();
        cfi_code_builder = std::make_unique<arrow::StringBuilder>();
        year_builder = std::make_unique<arrow::UInt16Builder>();
        month_builder = std::make_unique<arrow::UInt8Builder>();
        day_builder = std::make_unique<arrow::UInt8Builder>();
        week_builder = std::make_unique<arrow::UInt8Builder>();
        currency_builder = std::make_unique<arrow::StringBuilder>();
        settl_currency_builder = std::make_unique<arrow::StringBuilder>();
        match_algorithm_builder = std::make_unique<arrow::StringBuilder>();
        min_trade_vol_builder = std::make_unique<arrow::UInt32Builder>();
        max_trade_vol_builder = std::make_unique<arrow::UInt32Builder>();
        min_price_increment_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinPriceIncrement::precision, MinPriceIncrement::scale));
        display_factor_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(DisplayFactor::precision, DisplayFactor::scale));
        main_fraction_builder = std::make_unique<arrow::UInt8Builder>();
        sub_fraction_builder = std::make_unique<arrow::UInt8Builder>();
        price_display_format_builder = std::make_unique<arrow::UInt8Builder>();
        unit_of_measure_builder = std::make_unique<arrow::StringBuilder>();
        unit_of_measure_qty_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(UnitOfMeasureQty::precision, UnitOfMeasureQty::scale));
        trading_reference_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(TradingReferencePrice::precision, TradingReferencePrice::scale));
        open_interest_qty_builder = std::make_unique<arrow::Int32Builder>();
        cleared_volume_builder = std::make_unique<arrow::Int32Builder>();
        high_limit_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(HighLimitPrice::precision, HighLimitPrice::scale));
        low_limit_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(LowLimitPrice::precision, LowLimitPrice::scale));
        max_price_variation_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MaxPriceVariation::precision, MaxPriceVariation::scale));
        decay_quantity_builder = std::make_unique<arrow::Int32Builder>();
        decay_start_date_builder = std::make_unique<arrow::UInt16Builder>();
        original_contract_size_builder = std::make_unique<arrow::Int32Builder>();
        contract_multiplier_builder = std::make_unique<arrow::Int32Builder>();
        contract_multiplier_unit_builder = std::make_unique<arrow::Int8Builder>();
        flow_schedule_type_builder = std::make_unique<arrow::Int8Builder>();
        min_price_increment_amount_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinPriceIncrementAmount::precision, MinPriceIncrementAmount::scale));
        user_defined_instrument_builder = std::make_unique<arrow::StringBuilder>();
        trading_reference_date_builder = std::make_unique<arrow::UInt16Builder>();
        m_d_instrument_definition_future_27_no_events_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_future_27_no_m_d_feed_types_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_future_27_no_inst_attrib_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_future_27_no_lot_type_rules_group_builder = std::make_unique<arrow::StringBuilder>();
        underlying_product_optional_builder = std::make_unique<arrow::UInt8Builder>();
        security_sub_type_builder = std::make_unique<arrow::StringBuilder>();
        price_ratio_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(PriceRatio::precision, PriceRatio::scale));
        tick_rule_builder = std::make_unique<arrow::Int8Builder>();
        m_d_instrument_definition_spread_29_no_events_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_spread_29_no_m_d_feed_types_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_spread_29_no_inst_attrib_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_spread_29_no_lot_type_rules_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_spread_29_no_legs_group_builder = std::make_unique<arrow::StringBuilder>();
        security_id_optional_builder = std::make_unique<arrow::Int32Builder>();
        trade_date_builder = std::make_unique<arrow::UInt16Builder>();
        security_trading_status_builder = std::make_unique<arrow::UInt8Builder>();
        halt_reason_builder = std::make_unique<arrow::UInt8Builder>();
        security_trading_event_builder = std::make_unique<arrow::UInt8Builder>();
        m_d_incremental_refresh_book_32_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_book_32_no_order_i_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_trade_36_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        incremental_refresh_volume_group_builder = std::make_unique<arrow::StringBuilder>();
        last_msg_seq_num_processed_builder = std::make_unique<arrow::UInt32Builder>();
        tot_num_reports_builder = std::make_unique<arrow::UInt32Builder>();
        rpt_seq_builder = std::make_unique<arrow::UInt32Builder>();
        snapshot_full_refresh_38_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        quote_req_id_builder = std::make_unique<arrow::StringBuilder>();
        related_sym_group_builder = std::make_unique<arrow::StringBuilder>();
        put_or_call_builder = std::make_unique<arrow::UInt8Builder>();
        strike_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(StrikePrice::precision, StrikePrice::scale));
        strike_currency_builder = std::make_unique<arrow::StringBuilder>();
        min_cab_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinCabPrice::precision, MinCabPrice::scale));
        min_price_increment_optional_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinPriceIncrementOptional::precision, MinPriceIncrementOptional::scale));
        m_d_instrument_definition_option_41_no_events_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_option_41_no_m_d_feed_types_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_option_41_no_inst_attrib_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_option_41_no_lot_type_rules_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_option_41_no_underlyings_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_instrument_definition_option_41_no_related_instruments_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        m_d_incremental_refresh_order_book_43_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();
        no_chunks_builder = std::make_unique<arrow::UInt32Builder>();
        current_chunk_builder = std::make_unique<arrow::UInt32Builder>();
        snapshot_full_refresh_order_book_44_no_m_d_entries_group_builder = std::make_unique<arrow::StringBuilder>();

        row_count = 0;
    }

    // open output file
    void OpenOutput() {
        // generate output path
        auto path = output_path;
        if (options.max_file_size > 0) {
            auto dot = output_path.rfind('.');
            auto base = (dot != std::string::npos) ? output_path.substr(0, dot) : output_path;
            auto ext = (dot != std::string::npos) ? output_path.substr(dot) : std::string{};
            auto idx = std::to_string(file_index);
            while (idx.size() < 3) idx = "0" + idx;
            path = base + "_" + idx + ext;
        }
        outfile = *arrow::io::FileOutputStream::Open(path);

        // compression
        auto compression = parquet::Compression::ZSTD;
        if (options.compression == "snappy") compression = parquet::Compression::SNAPPY;
        else if (options.compression == "gzip") compression = parquet::Compression::GZIP;
        else if (options.compression == "lz4") compression = parquet::Compression::LZ4_FRAME;
        else if (options.compression == "brotli") compression = parquet::Compression::BROTLI;
        else if (options.compression == "none") compression = parquet::Compression::UNCOMPRESSED;

        // writer properties
        parquet::WriterProperties::Builder props;
        props.compression(compression);
        if (compression == parquet::Compression::ZSTD || compression == parquet::Compression::GZIP || compression == parquet::Compression::BROTLI)
            props.compression_level(options.compression_level);
        props.data_pagesize(options.data_page_size);
        props.dictionary_pagesize_limit(options.dictionary_page_size);
        if (options.dictionary_enabled) props.enable_dictionary();
        else props.disable_dictionary();
        if (options.write_statistics) props.enable_statistics();
        else props.disable_statistics();
        if (options.version == "1.0") props.version(parquet::ParquetVersion::PARQUET_1_0);
        else props.version(parquet::ParquetVersion::PARQUET_2_6);

        PARQUET_ASSIGN_OR_THROW(writer,
            parquet::arrow::FileWriter::Open(
                *schema,
                arrow::default_memory_pool(),
                outfile,
                props.build()));

        reset();
    }
  protected:
    std::shared_ptr<arrow::Schema> schema;
    std::int64_t max_rows;
    std::string output_path;
    parquet::Options options;
    std::int64_t row_count = 0;
    std::int64_t file_index = 0;
    std::int64_t estimated_bytes = 0;
    std::shared_ptr<arrow::io::OutputStream> outfile;
    std::unique_ptr<parquet::arrow::FileWriter> writer;
  protected:
        std::unique_ptr<arrow::StringBuilder> event_type_builder;
        std::unique_ptr<arrow::UInt32Builder> packet_sequence_number_builder;
        std::unique_ptr<arrow::Time64Builder> sending_time_builder;
        std::unique_ptr<arrow::Time64Builder> transact_time_builder;
        std::unique_ptr<arrow::UInt16Builder> block_length_builder;
        std::unique_ptr<arrow::UInt8Builder> num_in_group_builder;
        std::unique_ptr<arrow::StringBuilder> channel_reset_group_builder;
        std::unique_ptr<arrow::Int8Builder> heart_bt_int_builder;
        std::unique_ptr<arrow::StringBuilder> text_builder;
        std::unique_ptr<arrow::UInt32Builder> tot_num_reports_optional_builder;
        std::unique_ptr<arrow::StringBuilder> security_update_action_builder;
        std::unique_ptr<arrow::Time64Builder> last_update_time_builder;
        std::unique_ptr<arrow::UInt8Builder> md_security_trading_status_builder;
        std::unique_ptr<arrow::Int16Builder> appl_id_builder;
        std::unique_ptr<arrow::UInt8Builder> market_segment_id_builder;
        std::unique_ptr<arrow::UInt8Builder> underlying_product_builder;
        std::unique_ptr<arrow::StringBuilder> security_exchange_builder;
        std::unique_ptr<arrow::StringBuilder> security_group_builder;
        std::unique_ptr<arrow::StringBuilder> asset_builder;
        std::unique_ptr<arrow::StringBuilder> symbol_builder;
        std::unique_ptr<arrow::Int32Builder> security_id_builder;
        std::unique_ptr<arrow::StringBuilder> security_type_builder;
        std::unique_ptr<arrow::StringBuilder> cfi_code_builder;
        std::unique_ptr<arrow::UInt16Builder> year_builder;
        std::unique_ptr<arrow::UInt8Builder> month_builder;
        std::unique_ptr<arrow::UInt8Builder> day_builder;
        std::unique_ptr<arrow::UInt8Builder> week_builder;
        std::unique_ptr<arrow::StringBuilder> currency_builder;
        std::unique_ptr<arrow::StringBuilder> settl_currency_builder;
        std::unique_ptr<arrow::StringBuilder> match_algorithm_builder;
        std::unique_ptr<arrow::UInt32Builder> min_trade_vol_builder;
        std::unique_ptr<arrow::UInt32Builder> max_trade_vol_builder;
        std::unique_ptr<arrow::Decimal128Builder> min_price_increment_builder;
        std::unique_ptr<arrow::Decimal128Builder> display_factor_builder;
        std::unique_ptr<arrow::UInt8Builder> main_fraction_builder;
        std::unique_ptr<arrow::UInt8Builder> sub_fraction_builder;
        std::unique_ptr<arrow::UInt8Builder> price_display_format_builder;
        std::unique_ptr<arrow::StringBuilder> unit_of_measure_builder;
        std::unique_ptr<arrow::Decimal128Builder> unit_of_measure_qty_builder;
        std::unique_ptr<arrow::Decimal128Builder> trading_reference_price_builder;
        std::unique_ptr<arrow::Int32Builder> open_interest_qty_builder;
        std::unique_ptr<arrow::Int32Builder> cleared_volume_builder;
        std::unique_ptr<arrow::Decimal128Builder> high_limit_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> low_limit_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> max_price_variation_builder;
        std::unique_ptr<arrow::Int32Builder> decay_quantity_builder;
        std::unique_ptr<arrow::UInt16Builder> decay_start_date_builder;
        std::unique_ptr<arrow::Int32Builder> original_contract_size_builder;
        std::unique_ptr<arrow::Int32Builder> contract_multiplier_builder;
        std::unique_ptr<arrow::Int8Builder> contract_multiplier_unit_builder;
        std::unique_ptr<arrow::Int8Builder> flow_schedule_type_builder;
        std::unique_ptr<arrow::Decimal128Builder> min_price_increment_amount_builder;
        std::unique_ptr<arrow::StringBuilder> user_defined_instrument_builder;
        std::unique_ptr<arrow::UInt16Builder> trading_reference_date_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_future_27_no_events_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_future_27_no_m_d_feed_types_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_future_27_no_inst_attrib_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_future_27_no_lot_type_rules_group_builder;
        std::unique_ptr<arrow::UInt8Builder> underlying_product_optional_builder;
        std::unique_ptr<arrow::StringBuilder> security_sub_type_builder;
        std::unique_ptr<arrow::Decimal128Builder> price_ratio_builder;
        std::unique_ptr<arrow::Int8Builder> tick_rule_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_spread_29_no_events_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_spread_29_no_m_d_feed_types_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_spread_29_no_inst_attrib_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_spread_29_no_lot_type_rules_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_spread_29_no_legs_group_builder;
        std::unique_ptr<arrow::Int32Builder> security_id_optional_builder;
        std::unique_ptr<arrow::UInt16Builder> trade_date_builder;
        std::unique_ptr<arrow::UInt8Builder> security_trading_status_builder;
        std::unique_ptr<arrow::UInt8Builder> halt_reason_builder;
        std::unique_ptr<arrow::UInt8Builder> security_trading_event_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_book_32_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_book_32_no_order_i_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_daily_statistics_33_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_limits_banding_34_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_session_statistics_35_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_trade_36_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> incremental_refresh_volume_group_builder;
        std::unique_ptr<arrow::UInt32Builder> last_msg_seq_num_processed_builder;
        std::unique_ptr<arrow::UInt32Builder> tot_num_reports_builder;
        std::unique_ptr<arrow::UInt32Builder> rpt_seq_builder;
        std::unique_ptr<arrow::StringBuilder> snapshot_full_refresh_38_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> quote_req_id_builder;
        std::unique_ptr<arrow::StringBuilder> related_sym_group_builder;
        std::unique_ptr<arrow::UInt8Builder> put_or_call_builder;
        std::unique_ptr<arrow::Decimal128Builder> strike_price_builder;
        std::unique_ptr<arrow::StringBuilder> strike_currency_builder;
        std::unique_ptr<arrow::Decimal128Builder> min_cab_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> min_price_increment_optional_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_option_41_no_events_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_option_41_no_m_d_feed_types_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_option_41_no_inst_attrib_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_option_41_no_lot_type_rules_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_option_41_no_underlyings_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_instrument_definition_option_41_no_related_instruments_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_trade_summary_42_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_trade_summary_42_no_order_i_d_entries_group_builder;
        std::unique_ptr<arrow::StringBuilder> m_d_incremental_refresh_order_book_43_no_m_d_entries_group_builder;
        std::unique_ptr<arrow::UInt32Builder> no_chunks_builder;
        std::unique_ptr<arrow::UInt32Builder> current_chunk_builder;
        std::unique_ptr<arrow::StringBuilder> snapshot_full_refresh_order_book_44_no_m_d_entries_group_builder;
};
}
