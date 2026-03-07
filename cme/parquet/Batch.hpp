#pragma once

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/util/byte_size.h>
#include <parquet/arrow/writer.h>

#include "Record.hpp"

namespace cme {
struct ArrowBatch {

    ArrowBatch(std::shared_ptr<arrow::Schema> schema, const parquet::Options& options)
        : schema_(std::move(schema)),
          max_rows_(options.max_row_group_size),
          output_path_(options.file),
          options_(options)
    {
        OpenOutput();
    }

    // batch writer
    arrow::Status write(const ArrowRecord& record) {
        if (!writer_) {
            OpenOutput();
        }
        ARROW_RETURN_NOT_OK(record.event_type.append(*event_type_builder));
        ARROW_RETURN_NOT_OK(record.transact_time.append(*transact_time_builder));
        ARROW_RETURN_NOT_OK(record.block_length.append(*block_length_builder));
        ARROW_RETURN_NOT_OK(record.num_in_group.append(*num_in_group_builder));
        ARROW_RETURN_NOT_OK(record.appl_id.append(*appl_id_builder));
        ARROW_RETURN_NOT_OK(record.heart_bt_int.append(*heart_bt_int_builder));
        ARROW_RETURN_NOT_OK(record.text.append(*text_builder));
        ARROW_RETURN_NOT_OK(record.tot_num_reports_optional.append(*tot_num_reports_optional_builder));
        ARROW_RETURN_NOT_OK(record.security_update_action.append(*security_update_action_builder));
        ARROW_RETURN_NOT_OK(record.last_update_time.append(*last_update_time_builder));
        ARROW_RETURN_NOT_OK(record.md_security_trading_status.append(*md_security_trading_status_builder));
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
        ARROW_RETURN_NOT_OK(record.event_time.append(*event_time_builder));
        ARROW_RETURN_NOT_OK(record.md_feed_type.append(*md_feed_type_builder));
        ARROW_RETURN_NOT_OK(record.market_depth.append(*market_depth_builder));
        ARROW_RETURN_NOT_OK(record.lot_type.append(*lot_type_builder));
        ARROW_RETURN_NOT_OK(record.min_lot_size.append(*min_lot_size_builder));
        ARROW_RETURN_NOT_OK(record.underlying_product_optional.append(*underlying_product_optional_builder));
        ARROW_RETURN_NOT_OK(record.security_sub_type.append(*security_sub_type_builder));
        ARROW_RETURN_NOT_OK(record.price_ratio.append(*price_ratio_builder));
        ARROW_RETURN_NOT_OK(record.tick_rule.append(*tick_rule_builder));
        ARROW_RETURN_NOT_OK(record.leg_security_id.append(*leg_security_id_builder));
        ARROW_RETURN_NOT_OK(record.leg_side.append(*leg_side_builder));
        ARROW_RETURN_NOT_OK(record.leg_ratio_qty.append(*leg_ratio_qty_builder));
        ARROW_RETURN_NOT_OK(record.leg_price.append(*leg_price_builder));
        ARROW_RETURN_NOT_OK(record.leg_option_delta.append(*leg_option_delta_builder));
        ARROW_RETURN_NOT_OK(record.security_id_optional.append(*security_id_optional_builder));
        ARROW_RETURN_NOT_OK(record.trade_date.append(*trade_date_builder));
        ARROW_RETURN_NOT_OK(record.security_trading_status.append(*security_trading_status_builder));
        ARROW_RETURN_NOT_OK(record.halt_reason.append(*halt_reason_builder));
        ARROW_RETURN_NOT_OK(record.security_trading_event.append(*security_trading_event_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_px_optional.append(*md_entry_px_optional_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_size_optional.append(*md_entry_size_optional_builder));
        ARROW_RETURN_NOT_OK(record.rpt_seq.append(*rpt_seq_builder));
        ARROW_RETURN_NOT_OK(record.number_of_orders.append(*number_of_orders_builder));
        ARROW_RETURN_NOT_OK(record.md_price_level.append(*md_price_level_builder));
        ARROW_RETURN_NOT_OK(record.md_update_action.append(*md_update_action_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_type_book.append(*md_entry_type_book_builder));
        ARROW_RETURN_NOT_OK(record.order_id.append(*order_id_builder));
        ARROW_RETURN_NOT_OK(record.md_order_priority.append(*md_order_priority_builder));
        ARROW_RETURN_NOT_OK(record.md_display_qty_optional.append(*md_display_qty_optional_builder));
        ARROW_RETURN_NOT_OK(record.reference_id.append(*reference_id_builder));
        ARROW_RETURN_NOT_OK(record.order_update_action.append(*order_update_action_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_type_daily_statistics.append(*md_entry_type_daily_statistics_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_px.append(*md_entry_px_builder));
        ARROW_RETURN_NOT_OK(record.open_close_settl_flag.append(*open_close_settl_flag_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_type_statistics.append(*md_entry_type_statistics_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_size.append(*md_entry_size_builder));
        ARROW_RETURN_NOT_OK(record.trade_id.append(*trade_id_builder));
        ARROW_RETURN_NOT_OK(record.aggressor_side.append(*aggressor_side_builder));
        ARROW_RETURN_NOT_OK(record.last_msg_seq_num_processed.append(*last_msg_seq_num_processed_builder));
        ARROW_RETURN_NOT_OK(record.tot_num_reports.append(*tot_num_reports_builder));
        ARROW_RETURN_NOT_OK(record.md_price_level_optional.append(*md_price_level_optional_builder));
        ARROW_RETURN_NOT_OK(record.md_entry_type_.append(*md_entry_type__builder));
        ARROW_RETURN_NOT_OK(record.quote_req_id.append(*quote_req_id_builder));
        ARROW_RETURN_NOT_OK(record.order_qty.append(*order_qty_builder));
        ARROW_RETURN_NOT_OK(record.quote_type.append(*quote_type_builder));
        ARROW_RETURN_NOT_OK(record.side.append(*side_builder));
        ARROW_RETURN_NOT_OK(record.put_or_call.append(*put_or_call_builder));
        ARROW_RETURN_NOT_OK(record.strike_price.append(*strike_price_builder));
        ARROW_RETURN_NOT_OK(record.strike_currency.append(*strike_currency_builder));
        ARROW_RETURN_NOT_OK(record.min_cab_price.append(*min_cab_price_builder));
        ARROW_RETURN_NOT_OK(record.min_price_increment_optional.append(*min_price_increment_optional_builder));
        ARROW_RETURN_NOT_OK(record.underlying_security_id.append(*underlying_security_id_builder));
        ARROW_RETURN_NOT_OK(record.underlying_symbol.append(*underlying_symbol_builder));
        ARROW_RETURN_NOT_OK(record.related_security_id.append(*related_security_id_builder));
        ARROW_RETURN_NOT_OK(record.related_symbol.append(*related_symbol_builder));
        ARROW_RETURN_NOT_OK(record.md_trade_entry_id.append(*md_trade_entry_id_builder));
        ARROW_RETURN_NOT_OK(record.last_qty.append(*last_qty_builder));
        ARROW_RETURN_NOT_OK(record.order_id_optional.append(*order_id_optional_builder));
        ARROW_RETURN_NOT_OK(record.no_chunks.append(*no_chunks_builder));
        ARROW_RETURN_NOT_OK(record.current_chunk.append(*current_chunk_builder));
        ARROW_RETURN_NOT_OK(record.md_display_qty.append(*md_display_qty_builder));

        row_count_++;

        if (row_count_ >= max_rows_) {
            return flush();
        }

        return arrow::Status::OK();
    }

    // flush batch
    arrow::Status flush() {
        if (row_count_ == 0) {
            return arrow::Status::OK();
        }

        std::shared_ptr<arrow::Array> event_type_column;
        std::shared_ptr<arrow::Array> transact_time_column;
        std::shared_ptr<arrow::Array> block_length_column;
        std::shared_ptr<arrow::Array> num_in_group_column;
        std::shared_ptr<arrow::Array> appl_id_column;
        std::shared_ptr<arrow::Array> heart_bt_int_column;
        std::shared_ptr<arrow::Array> text_column;
        std::shared_ptr<arrow::Array> tot_num_reports_optional_column;
        std::shared_ptr<arrow::Array> security_update_action_column;
        std::shared_ptr<arrow::Array> last_update_time_column;
        std::shared_ptr<arrow::Array> md_security_trading_status_column;
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
        std::shared_ptr<arrow::Array> event_time_column;
        std::shared_ptr<arrow::Array> md_feed_type_column;
        std::shared_ptr<arrow::Array> market_depth_column;
        std::shared_ptr<arrow::Array> lot_type_column;
        std::shared_ptr<arrow::Array> min_lot_size_column;
        std::shared_ptr<arrow::Array> underlying_product_optional_column;
        std::shared_ptr<arrow::Array> security_sub_type_column;
        std::shared_ptr<arrow::Array> price_ratio_column;
        std::shared_ptr<arrow::Array> tick_rule_column;
        std::shared_ptr<arrow::Array> leg_security_id_column;
        std::shared_ptr<arrow::Array> leg_side_column;
        std::shared_ptr<arrow::Array> leg_ratio_qty_column;
        std::shared_ptr<arrow::Array> leg_price_column;
        std::shared_ptr<arrow::Array> leg_option_delta_column;
        std::shared_ptr<arrow::Array> security_id_optional_column;
        std::shared_ptr<arrow::Array> trade_date_column;
        std::shared_ptr<arrow::Array> security_trading_status_column;
        std::shared_ptr<arrow::Array> halt_reason_column;
        std::shared_ptr<arrow::Array> security_trading_event_column;
        std::shared_ptr<arrow::Array> md_entry_px_optional_column;
        std::shared_ptr<arrow::Array> md_entry_size_optional_column;
        std::shared_ptr<arrow::Array> rpt_seq_column;
        std::shared_ptr<arrow::Array> number_of_orders_column;
        std::shared_ptr<arrow::Array> md_price_level_column;
        std::shared_ptr<arrow::Array> md_update_action_column;
        std::shared_ptr<arrow::Array> md_entry_type_book_column;
        std::shared_ptr<arrow::Array> order_id_column;
        std::shared_ptr<arrow::Array> md_order_priority_column;
        std::shared_ptr<arrow::Array> md_display_qty_optional_column;
        std::shared_ptr<arrow::Array> reference_id_column;
        std::shared_ptr<arrow::Array> order_update_action_column;
        std::shared_ptr<arrow::Array> md_entry_type_daily_statistics_column;
        std::shared_ptr<arrow::Array> md_entry_px_column;
        std::shared_ptr<arrow::Array> open_close_settl_flag_column;
        std::shared_ptr<arrow::Array> md_entry_type_statistics_column;
        std::shared_ptr<arrow::Array> md_entry_size_column;
        std::shared_ptr<arrow::Array> trade_id_column;
        std::shared_ptr<arrow::Array> aggressor_side_column;
        std::shared_ptr<arrow::Array> last_msg_seq_num_processed_column;
        std::shared_ptr<arrow::Array> tot_num_reports_column;
        std::shared_ptr<arrow::Array> md_price_level_optional_column;
        std::shared_ptr<arrow::Array> md_entry_type__column;
        std::shared_ptr<arrow::Array> quote_req_id_column;
        std::shared_ptr<arrow::Array> order_qty_column;
        std::shared_ptr<arrow::Array> quote_type_column;
        std::shared_ptr<arrow::Array> side_column;
        std::shared_ptr<arrow::Array> put_or_call_column;
        std::shared_ptr<arrow::Array> strike_price_column;
        std::shared_ptr<arrow::Array> strike_currency_column;
        std::shared_ptr<arrow::Array> min_cab_price_column;
        std::shared_ptr<arrow::Array> min_price_increment_optional_column;
        std::shared_ptr<arrow::Array> underlying_security_id_column;
        std::shared_ptr<arrow::Array> underlying_symbol_column;
        std::shared_ptr<arrow::Array> related_security_id_column;
        std::shared_ptr<arrow::Array> related_symbol_column;
        std::shared_ptr<arrow::Array> md_trade_entry_id_column;
        std::shared_ptr<arrow::Array> last_qty_column;
        std::shared_ptr<arrow::Array> order_id_optional_column;
        std::shared_ptr<arrow::Array> no_chunks_column;
        std::shared_ptr<arrow::Array> current_chunk_column;
        std::shared_ptr<arrow::Array> md_display_qty_column;

        ARROW_RETURN_NOT_OK(event_type_builder->Finish(&event_type_column));
        ARROW_RETURN_NOT_OK(transact_time_builder->Finish(&transact_time_column));
        ARROW_RETURN_NOT_OK(block_length_builder->Finish(&block_length_column));
        ARROW_RETURN_NOT_OK(num_in_group_builder->Finish(&num_in_group_column));
        ARROW_RETURN_NOT_OK(appl_id_builder->Finish(&appl_id_column));
        ARROW_RETURN_NOT_OK(heart_bt_int_builder->Finish(&heart_bt_int_column));
        ARROW_RETURN_NOT_OK(text_builder->Finish(&text_column));
        ARROW_RETURN_NOT_OK(tot_num_reports_optional_builder->Finish(&tot_num_reports_optional_column));
        ARROW_RETURN_NOT_OK(security_update_action_builder->Finish(&security_update_action_column));
        ARROW_RETURN_NOT_OK(last_update_time_builder->Finish(&last_update_time_column));
        ARROW_RETURN_NOT_OK(md_security_trading_status_builder->Finish(&md_security_trading_status_column));
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
        ARROW_RETURN_NOT_OK(event_time_builder->Finish(&event_time_column));
        ARROW_RETURN_NOT_OK(md_feed_type_builder->Finish(&md_feed_type_column));
        ARROW_RETURN_NOT_OK(market_depth_builder->Finish(&market_depth_column));
        ARROW_RETURN_NOT_OK(lot_type_builder->Finish(&lot_type_column));
        ARROW_RETURN_NOT_OK(min_lot_size_builder->Finish(&min_lot_size_column));
        ARROW_RETURN_NOT_OK(underlying_product_optional_builder->Finish(&underlying_product_optional_column));
        ARROW_RETURN_NOT_OK(security_sub_type_builder->Finish(&security_sub_type_column));
        ARROW_RETURN_NOT_OK(price_ratio_builder->Finish(&price_ratio_column));
        ARROW_RETURN_NOT_OK(tick_rule_builder->Finish(&tick_rule_column));
        ARROW_RETURN_NOT_OK(leg_security_id_builder->Finish(&leg_security_id_column));
        ARROW_RETURN_NOT_OK(leg_side_builder->Finish(&leg_side_column));
        ARROW_RETURN_NOT_OK(leg_ratio_qty_builder->Finish(&leg_ratio_qty_column));
        ARROW_RETURN_NOT_OK(leg_price_builder->Finish(&leg_price_column));
        ARROW_RETURN_NOT_OK(leg_option_delta_builder->Finish(&leg_option_delta_column));
        ARROW_RETURN_NOT_OK(security_id_optional_builder->Finish(&security_id_optional_column));
        ARROW_RETURN_NOT_OK(trade_date_builder->Finish(&trade_date_column));
        ARROW_RETURN_NOT_OK(security_trading_status_builder->Finish(&security_trading_status_column));
        ARROW_RETURN_NOT_OK(halt_reason_builder->Finish(&halt_reason_column));
        ARROW_RETURN_NOT_OK(security_trading_event_builder->Finish(&security_trading_event_column));
        ARROW_RETURN_NOT_OK(md_entry_px_optional_builder->Finish(&md_entry_px_optional_column));
        ARROW_RETURN_NOT_OK(md_entry_size_optional_builder->Finish(&md_entry_size_optional_column));
        ARROW_RETURN_NOT_OK(rpt_seq_builder->Finish(&rpt_seq_column));
        ARROW_RETURN_NOT_OK(number_of_orders_builder->Finish(&number_of_orders_column));
        ARROW_RETURN_NOT_OK(md_price_level_builder->Finish(&md_price_level_column));
        ARROW_RETURN_NOT_OK(md_update_action_builder->Finish(&md_update_action_column));
        ARROW_RETURN_NOT_OK(md_entry_type_book_builder->Finish(&md_entry_type_book_column));
        ARROW_RETURN_NOT_OK(order_id_builder->Finish(&order_id_column));
        ARROW_RETURN_NOT_OK(md_order_priority_builder->Finish(&md_order_priority_column));
        ARROW_RETURN_NOT_OK(md_display_qty_optional_builder->Finish(&md_display_qty_optional_column));
        ARROW_RETURN_NOT_OK(reference_id_builder->Finish(&reference_id_column));
        ARROW_RETURN_NOT_OK(order_update_action_builder->Finish(&order_update_action_column));
        ARROW_RETURN_NOT_OK(md_entry_type_daily_statistics_builder->Finish(&md_entry_type_daily_statistics_column));
        ARROW_RETURN_NOT_OK(md_entry_px_builder->Finish(&md_entry_px_column));
        ARROW_RETURN_NOT_OK(open_close_settl_flag_builder->Finish(&open_close_settl_flag_column));
        ARROW_RETURN_NOT_OK(md_entry_type_statistics_builder->Finish(&md_entry_type_statistics_column));
        ARROW_RETURN_NOT_OK(md_entry_size_builder->Finish(&md_entry_size_column));
        ARROW_RETURN_NOT_OK(trade_id_builder->Finish(&trade_id_column));
        ARROW_RETURN_NOT_OK(aggressor_side_builder->Finish(&aggressor_side_column));
        ARROW_RETURN_NOT_OK(last_msg_seq_num_processed_builder->Finish(&last_msg_seq_num_processed_column));
        ARROW_RETURN_NOT_OK(tot_num_reports_builder->Finish(&tot_num_reports_column));
        ARROW_RETURN_NOT_OK(md_price_level_optional_builder->Finish(&md_price_level_optional_column));
        ARROW_RETURN_NOT_OK(md_entry_type__builder->Finish(&md_entry_type__column));
        ARROW_RETURN_NOT_OK(quote_req_id_builder->Finish(&quote_req_id_column));
        ARROW_RETURN_NOT_OK(order_qty_builder->Finish(&order_qty_column));
        ARROW_RETURN_NOT_OK(quote_type_builder->Finish(&quote_type_column));
        ARROW_RETURN_NOT_OK(side_builder->Finish(&side_column));
        ARROW_RETURN_NOT_OK(put_or_call_builder->Finish(&put_or_call_column));
        ARROW_RETURN_NOT_OK(strike_price_builder->Finish(&strike_price_column));
        ARROW_RETURN_NOT_OK(strike_currency_builder->Finish(&strike_currency_column));
        ARROW_RETURN_NOT_OK(min_cab_price_builder->Finish(&min_cab_price_column));
        ARROW_RETURN_NOT_OK(min_price_increment_optional_builder->Finish(&min_price_increment_optional_column));
        ARROW_RETURN_NOT_OK(underlying_security_id_builder->Finish(&underlying_security_id_column));
        ARROW_RETURN_NOT_OK(underlying_symbol_builder->Finish(&underlying_symbol_column));
        ARROW_RETURN_NOT_OK(related_security_id_builder->Finish(&related_security_id_column));
        ARROW_RETURN_NOT_OK(related_symbol_builder->Finish(&related_symbol_column));
        ARROW_RETURN_NOT_OK(md_trade_entry_id_builder->Finish(&md_trade_entry_id_column));
        ARROW_RETURN_NOT_OK(last_qty_builder->Finish(&last_qty_column));
        ARROW_RETURN_NOT_OK(order_id_optional_builder->Finish(&order_id_optional_column));
        ARROW_RETURN_NOT_OK(no_chunks_builder->Finish(&no_chunks_column));
        ARROW_RETURN_NOT_OK(current_chunk_builder->Finish(&current_chunk_column));
        ARROW_RETURN_NOT_OK(md_display_qty_builder->Finish(&md_display_qty_column));

        auto batch = arrow::RecordBatch::Make(schema_, row_count_, {
            event_type_column,
            transact_time_column,
            block_length_column,
            num_in_group_column,
            appl_id_column,
            heart_bt_int_column,
            text_column,
            tot_num_reports_optional_column,
            security_update_action_column,
            last_update_time_column,
            md_security_trading_status_column,
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
            event_time_column,
            md_feed_type_column,
            market_depth_column,
            lot_type_column,
            min_lot_size_column,
            underlying_product_optional_column,
            security_sub_type_column,
            price_ratio_column,
            tick_rule_column,
            leg_security_id_column,
            leg_side_column,
            leg_ratio_qty_column,
            leg_price_column,
            leg_option_delta_column,
            security_id_optional_column,
            trade_date_column,
            security_trading_status_column,
            halt_reason_column,
            security_trading_event_column,
            md_entry_px_optional_column,
            md_entry_size_optional_column,
            rpt_seq_column,
            number_of_orders_column,
            md_price_level_column,
            md_update_action_column,
            md_entry_type_book_column,
            order_id_column,
            md_order_priority_column,
            md_display_qty_optional_column,
            reference_id_column,
            order_update_action_column,
            md_entry_type_daily_statistics_column,
            md_entry_px_column,
            open_close_settl_flag_column,
            md_entry_type_statistics_column,
            md_entry_size_column,
            trade_id_column,
            aggressor_side_column,
            last_msg_seq_num_processed_column,
            tot_num_reports_column,
            md_price_level_optional_column,
            md_entry_type__column,
            quote_req_id_column,
            order_qty_column,
            quote_type_column,
            side_column,
            put_or_call_column,
            strike_price_column,
            strike_currency_column,
            min_cab_price_column,
            min_price_increment_optional_column,
            underlying_security_id_column,
            underlying_symbol_column,
            related_security_id_column,
            related_symbol_column,
            md_trade_entry_id_column,
            last_qty_column,
            order_id_optional_column,
            no_chunks_column,
            current_chunk_column,
            md_display_qty_column,
        } );

        ARROW_RETURN_NOT_OK(writer_->WriteRecordBatch(*batch));
        estimated_bytes_ += arrow::util::TotalBufferSize(*batch);

        // roll to next file if size limit exceeded
        if (options_.max_file_size > 0 && estimated_bytes_ >= options_.max_file_size) {
            ARROW_RETURN_NOT_OK(writer_->Close());
            writer_.reset();
            estimated_bytes_ = 0;
            file_index_++;
            return arrow::Status::OK();
        }

        reset();

        return arrow::Status::OK();
    }

    // close file
    arrow::Status close() {
        ARROW_RETURN_NOT_OK(flush());
        if (writer_) {
            return writer_->Close();
        }
        return arrow::Status::OK();
    }
  protected:

    // reset arrow builders
    void reset() {
        event_type_builder = std::make_unique<arrow::StringBuilder>();
        transact_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        block_length_builder = std::make_unique<arrow::UInt16Builder>();
        num_in_group_builder = std::make_unique<arrow::UInt8Builder>();
        appl_id_builder = std::make_unique<arrow::Int16Builder>();
        heart_bt_int_builder = std::make_unique<arrow::Int8Builder>();
        text_builder = std::make_unique<arrow::StringBuilder>();
        tot_num_reports_optional_builder = std::make_unique<arrow::UInt32Builder>();
        security_update_action_builder = std::make_unique<arrow::StringBuilder>();
        last_update_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        md_security_trading_status_builder = std::make_unique<arrow::UInt8Builder>();
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
        event_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        md_feed_type_builder = std::make_unique<arrow::StringBuilder>();
        market_depth_builder = std::make_unique<arrow::Int8Builder>();
        lot_type_builder = std::make_unique<arrow::Int8Builder>();
        min_lot_size_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinLotSize::precision, MinLotSize::scale));
        underlying_product_optional_builder = std::make_unique<arrow::UInt8Builder>();
        security_sub_type_builder = std::make_unique<arrow::StringBuilder>();
        price_ratio_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(PriceRatio::precision, PriceRatio::scale));
        tick_rule_builder = std::make_unique<arrow::Int8Builder>();
        leg_security_id_builder = std::make_unique<arrow::Int32Builder>();
        leg_side_builder = std::make_unique<arrow::UInt8Builder>();
        leg_ratio_qty_builder = std::make_unique<arrow::Int8Builder>();
        leg_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(LegPrice::precision, LegPrice::scale));
        leg_option_delta_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(LegOptionDelta::precision, LegOptionDelta::scale));
        security_id_optional_builder = std::make_unique<arrow::Int32Builder>();
        trade_date_builder = std::make_unique<arrow::UInt16Builder>();
        security_trading_status_builder = std::make_unique<arrow::UInt8Builder>();
        halt_reason_builder = std::make_unique<arrow::UInt8Builder>();
        security_trading_event_builder = std::make_unique<arrow::UInt8Builder>();
        md_entry_px_optional_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MdEntryPxOptional::precision, MdEntryPxOptional::scale));
        md_entry_size_optional_builder = std::make_unique<arrow::Int32Builder>();
        rpt_seq_builder = std::make_unique<arrow::UInt32Builder>();
        number_of_orders_builder = std::make_unique<arrow::Int32Builder>();
        md_price_level_builder = std::make_unique<arrow::UInt8Builder>();
        md_update_action_builder = std::make_unique<arrow::UInt8Builder>();
        md_entry_type_book_builder = std::make_unique<arrow::StringBuilder>();
        order_id_builder = std::make_unique<arrow::UInt64Builder>();
        md_order_priority_builder = std::make_unique<arrow::UInt64Builder>();
        md_display_qty_optional_builder = std::make_unique<arrow::Int32Builder>();
        reference_id_builder = std::make_unique<arrow::UInt8Builder>();
        order_update_action_builder = std::make_unique<arrow::UInt8Builder>();
        md_entry_type_daily_statistics_builder = std::make_unique<arrow::StringBuilder>();
        md_entry_px_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MdEntryPx::precision, MdEntryPx::scale));
        open_close_settl_flag_builder = std::make_unique<arrow::UInt8Builder>();
        md_entry_type_statistics_builder = std::make_unique<arrow::StringBuilder>();
        md_entry_size_builder = std::make_unique<arrow::Int32Builder>();
        trade_id_builder = std::make_unique<arrow::Int32Builder>();
        aggressor_side_builder = std::make_unique<arrow::UInt8Builder>();
        last_msg_seq_num_processed_builder = std::make_unique<arrow::UInt32Builder>();
        tot_num_reports_builder = std::make_unique<arrow::UInt32Builder>();
        md_price_level_optional_builder = std::make_unique<arrow::Int8Builder>();
        md_entry_type__builder = std::make_unique<arrow::StringBuilder>();
        quote_req_id_builder = std::make_unique<arrow::StringBuilder>();
        order_qty_builder = std::make_unique<arrow::Int32Builder>();
        quote_type_builder = std::make_unique<arrow::Int8Builder>();
        side_builder = std::make_unique<arrow::Int8Builder>();
        put_or_call_builder = std::make_unique<arrow::UInt8Builder>();
        strike_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(StrikePrice::precision, StrikePrice::scale));
        strike_currency_builder = std::make_unique<arrow::StringBuilder>();
        min_cab_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinCabPrice::precision, MinCabPrice::scale));
        min_price_increment_optional_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinPriceIncrementOptional::precision, MinPriceIncrementOptional::scale));
        underlying_security_id_builder = std::make_unique<arrow::Int32Builder>();
        underlying_symbol_builder = std::make_unique<arrow::StringBuilder>();
        related_security_id_builder = std::make_unique<arrow::Int32Builder>();
        related_symbol_builder = std::make_unique<arrow::StringBuilder>();
        md_trade_entry_id_builder = std::make_unique<arrow::UInt32Builder>();
        last_qty_builder = std::make_unique<arrow::Int32Builder>();
        order_id_optional_builder = std::make_unique<arrow::UInt64Builder>();
        no_chunks_builder = std::make_unique<arrow::UInt32Builder>();
        current_chunk_builder = std::make_unique<arrow::UInt32Builder>();
        md_display_qty_builder = std::make_unique<arrow::Int32Builder>();

        row_count_ = 0;
    }

    // open output file
    void OpenOutput() {
        // generate output path
        auto path = output_path_;
        if (options_.max_file_size > 0) {
            auto dot = output_path_.rfind('.');
            auto base = (dot != std::string::npos) ? output_path_.substr(0, dot) : output_path_;
            auto ext = (dot != std::string::npos) ? output_path_.substr(dot) : std::string{};
            auto idx = std::to_string(file_index_);
            while (idx.size() < 3) idx = "0" + idx;
            path = base + "_" + idx + ext;
        }
        outfile_ = *arrow::io::FileOutputStream::Open(path);

        // compression
        auto compression = parquet::Compression::ZSTD;
        if (options_.compression == "snappy") compression = parquet::Compression::SNAPPY;
        else if (options_.compression == "gzip") compression = parquet::Compression::GZIP;
        else if (options_.compression == "lz4") compression = parquet::Compression::LZ4_FRAME;
        else if (options_.compression == "brotli") compression = parquet::Compression::BROTLI;
        else if (options_.compression == "none") compression = parquet::Compression::UNCOMPRESSED;

        // writer properties
        parquet::WriterProperties::Builder props;
        props.compression(compression);
        if (compression == parquet::Compression::ZSTD || compression == parquet::Compression::GZIP || compression == parquet::Compression::BROTLI)
            props.compression_level(options_.compression_level);
        props.data_pagesize(options_.data_page_size);
        props.dictionary_pagesize_limit(options_.dictionary_page_size);
        if (options_.dictionary_enabled) props.enable_dictionary();
        else props.disable_dictionary();
        if (options_.write_statistics) props.enable_statistics();
        else props.disable_statistics();
        if (options_.version == "1.0") props.version(parquet::ParquetVersion::PARQUET_1_0);
        else props.version(parquet::ParquetVersion::PARQUET_2_6);

        PARQUET_ASSIGN_OR_THROW(writer_,
            parquet::arrow::FileWriter::Open(
                *schema_,
                arrow::default_memory_pool(),
                outfile_,
                props.build()));

        reset();
    }
  protected:
    std::shared_ptr<arrow::Schema> schema_;
    std::int64_t max_rows_;
    std::string output_path_;
    parquet::Options options_;
    std::int64_t row_count_ = 0;
    std::int64_t file_index_ = 0;
    std::int64_t estimated_bytes_ = 0;
    std::shared_ptr<arrow::io::OutputStream> outfile_;
    std::unique_ptr<parquet::arrow::FileWriter> writer_;
  protected:
        std::unique_ptr<arrow::StringBuilder> event_type_builder;
        std::unique_ptr<arrow::Time64Builder> transact_time_builder;
        std::unique_ptr<arrow::UInt16Builder> block_length_builder;
        std::unique_ptr<arrow::UInt8Builder> num_in_group_builder;
        std::unique_ptr<arrow::Int16Builder> appl_id_builder;
        std::unique_ptr<arrow::Int8Builder> heart_bt_int_builder;
        std::unique_ptr<arrow::StringBuilder> text_builder;
        std::unique_ptr<arrow::UInt32Builder> tot_num_reports_optional_builder;
        std::unique_ptr<arrow::StringBuilder> security_update_action_builder;
        std::unique_ptr<arrow::Time64Builder> last_update_time_builder;
        std::unique_ptr<arrow::UInt8Builder> md_security_trading_status_builder;
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
        std::unique_ptr<arrow::Time64Builder> event_time_builder;
        std::unique_ptr<arrow::StringBuilder> md_feed_type_builder;
        std::unique_ptr<arrow::Int8Builder> market_depth_builder;
        std::unique_ptr<arrow::Int8Builder> lot_type_builder;
        std::unique_ptr<arrow::Decimal128Builder> min_lot_size_builder;
        std::unique_ptr<arrow::UInt8Builder> underlying_product_optional_builder;
        std::unique_ptr<arrow::StringBuilder> security_sub_type_builder;
        std::unique_ptr<arrow::Decimal128Builder> price_ratio_builder;
        std::unique_ptr<arrow::Int8Builder> tick_rule_builder;
        std::unique_ptr<arrow::Int32Builder> leg_security_id_builder;
        std::unique_ptr<arrow::UInt8Builder> leg_side_builder;
        std::unique_ptr<arrow::Int8Builder> leg_ratio_qty_builder;
        std::unique_ptr<arrow::Decimal128Builder> leg_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> leg_option_delta_builder;
        std::unique_ptr<arrow::Int32Builder> security_id_optional_builder;
        std::unique_ptr<arrow::UInt16Builder> trade_date_builder;
        std::unique_ptr<arrow::UInt8Builder> security_trading_status_builder;
        std::unique_ptr<arrow::UInt8Builder> halt_reason_builder;
        std::unique_ptr<arrow::UInt8Builder> security_trading_event_builder;
        std::unique_ptr<arrow::Decimal128Builder> md_entry_px_optional_builder;
        std::unique_ptr<arrow::Int32Builder> md_entry_size_optional_builder;
        std::unique_ptr<arrow::UInt32Builder> rpt_seq_builder;
        std::unique_ptr<arrow::Int32Builder> number_of_orders_builder;
        std::unique_ptr<arrow::UInt8Builder> md_price_level_builder;
        std::unique_ptr<arrow::UInt8Builder> md_update_action_builder;
        std::unique_ptr<arrow::StringBuilder> md_entry_type_book_builder;
        std::unique_ptr<arrow::UInt64Builder> order_id_builder;
        std::unique_ptr<arrow::UInt64Builder> md_order_priority_builder;
        std::unique_ptr<arrow::Int32Builder> md_display_qty_optional_builder;
        std::unique_ptr<arrow::UInt8Builder> reference_id_builder;
        std::unique_ptr<arrow::UInt8Builder> order_update_action_builder;
        std::unique_ptr<arrow::StringBuilder> md_entry_type_daily_statistics_builder;
        std::unique_ptr<arrow::Decimal128Builder> md_entry_px_builder;
        std::unique_ptr<arrow::UInt8Builder> open_close_settl_flag_builder;
        std::unique_ptr<arrow::StringBuilder> md_entry_type_statistics_builder;
        std::unique_ptr<arrow::Int32Builder> md_entry_size_builder;
        std::unique_ptr<arrow::Int32Builder> trade_id_builder;
        std::unique_ptr<arrow::UInt8Builder> aggressor_side_builder;
        std::unique_ptr<arrow::UInt32Builder> last_msg_seq_num_processed_builder;
        std::unique_ptr<arrow::UInt32Builder> tot_num_reports_builder;
        std::unique_ptr<arrow::Int8Builder> md_price_level_optional_builder;
        std::unique_ptr<arrow::StringBuilder> md_entry_type__builder;
        std::unique_ptr<arrow::StringBuilder> quote_req_id_builder;
        std::unique_ptr<arrow::Int32Builder> order_qty_builder;
        std::unique_ptr<arrow::Int8Builder> quote_type_builder;
        std::unique_ptr<arrow::Int8Builder> side_builder;
        std::unique_ptr<arrow::UInt8Builder> put_or_call_builder;
        std::unique_ptr<arrow::Decimal128Builder> strike_price_builder;
        std::unique_ptr<arrow::StringBuilder> strike_currency_builder;
        std::unique_ptr<arrow::Decimal128Builder> min_cab_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> min_price_increment_optional_builder;
        std::unique_ptr<arrow::Int32Builder> underlying_security_id_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_symbol_builder;
        std::unique_ptr<arrow::Int32Builder> related_security_id_builder;
        std::unique_ptr<arrow::StringBuilder> related_symbol_builder;
        std::unique_ptr<arrow::UInt32Builder> md_trade_entry_id_builder;
        std::unique_ptr<arrow::Int32Builder> last_qty_builder;
        std::unique_ptr<arrow::UInt64Builder> order_id_optional_builder;
        std::unique_ptr<arrow::UInt32Builder> no_chunks_builder;
        std::unique_ptr<arrow::UInt32Builder> current_chunk_builder;
        std::unique_ptr<arrow::Int32Builder> md_display_qty_builder;
};
}
