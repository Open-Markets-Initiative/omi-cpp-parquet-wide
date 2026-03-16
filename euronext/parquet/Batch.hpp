#pragma once

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/util/byte_size.h>
#include <parquet/arrow/writer.h>

#include "Record.hpp"

namespace euronext {
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
        ARROW_RETURN_NOT_OK(record.md_seq_num.append(*md_seq_num_builder));
        ARROW_RETURN_NOT_OK(record.session_trading_day.append(*session_trading_day_builder));
        ARROW_RETURN_NOT_OK(record.event_time.append(*event_time_builder));
        ARROW_RETURN_NOT_OK(record.md_seq_num_optional.append(*md_seq_num_optional_builder));
        ARROW_RETURN_NOT_OK(record.technical_notification_type.append(*technical_notification_type_builder));
        ARROW_RETURN_NOT_OK(record.rebroadcast_indicator.append(*rebroadcast_indicator_builder));
        ARROW_RETURN_NOT_OK(record.retransmission_start_time.append(*retransmission_start_time_builder));
        ARROW_RETURN_NOT_OK(record.retransmission_end_time.append(*retransmission_end_time_builder));
        ARROW_RETURN_NOT_OK(record.symbol_index_optional.append(*symbol_index_optional_builder));
        ARROW_RETURN_NOT_OK(record.emm.append(*emm_builder));
        ARROW_RETURN_NOT_OK(record.block_length_short.append(*block_length_short_builder));
        ARROW_RETURN_NOT_OK(record.num_in_group.append(*num_in_group_builder));
        ARROW_RETURN_NOT_OK(record.market_updates_group.append(*market_updates_group_builder));
        ARROW_RETURN_NOT_OK(record.order_updates_group.append(*order_updates_group_builder));
        ARROW_RETURN_NOT_OK(record.price_updates_group.append(*price_updates_group_builder));
        ARROW_RETURN_NOT_OK(record.trading_date_time.append(*trading_date_time_builder));
        ARROW_RETURN_NOT_OK(record.publication_date_time.append(*publication_date_time_builder));
        ARROW_RETURN_NOT_OK(record.trade_type.append(*trade_type_builder));
        ARROW_RETURN_NOT_OK(record.mifid_instrument_id_type_optional.append(*mifid_instrument_id_type_optional_builder));
        ARROW_RETURN_NOT_OK(record.mifid_instrument_id_optional.append(*mifid_instrument_id_optional_builder));
        ARROW_RETURN_NOT_OK(record.mifid_execution_id.append(*mifid_execution_id_builder));
        ARROW_RETURN_NOT_OK(record.mifid_price_optional.append(*mifid_price_optional_builder));
        ARROW_RETURN_NOT_OK(record.mifid_quantity.append(*mifid_quantity_builder));
        ARROW_RETURN_NOT_OK(record.mifid_price_notation.append(*mifid_price_notation_builder));
        ARROW_RETURN_NOT_OK(record.mifid_currency.append(*mifid_currency_builder));
        ARROW_RETURN_NOT_OK(record.mifid_qty_in_msrmt_unit_notation.append(*mifid_qty_in_msrmt_unit_notation_builder));
        ARROW_RETURN_NOT_OK(record.mifid_quantity_measurement_unit.append(*mifid_quantity_measurement_unit_builder));
        ARROW_RETURN_NOT_OK(record.mifid_notional_amount.append(*mifid_notional_amount_builder));
        ARROW_RETURN_NOT_OK(record.notional_currency.append(*notional_currency_builder));
        ARROW_RETURN_NOT_OK(record.mifid_clearing_flag.append(*mifid_clearing_flag_builder));
        ARROW_RETURN_NOT_OK(record.mmt_market_mechanism.append(*mmt_market_mechanism_builder));
        ARROW_RETURN_NOT_OK(record.mmt_trading_mode.append(*mmt_trading_mode_builder));
        ARROW_RETURN_NOT_OK(record.mmt_transaction_category.append(*mmt_transaction_category_builder));
        ARROW_RETURN_NOT_OK(record.mmt_negotiation_indicator.append(*mmt_negotiation_indicator_builder));
        ARROW_RETURN_NOT_OK(record.mmt_agency_cross_trade_indicator.append(*mmt_agency_cross_trade_indicator_builder));
        ARROW_RETURN_NOT_OK(record.mmt_modification_indicator_char_4_optional.append(*mmt_modification_indicator_char_4_optional_builder));
        ARROW_RETURN_NOT_OK(record.mmt_benchmark_indicator.append(*mmt_benchmark_indicator_builder));
        ARROW_RETURN_NOT_OK(record.mmt_special_dividend_indicator.append(*mmt_special_dividend_indicator_builder));
        ARROW_RETURN_NOT_OK(record.mmt_off_book_automated_indicator.append(*mmt_off_book_automated_indicator_builder));
        ARROW_RETURN_NOT_OK(record.mmt_contributionto_price.append(*mmt_contributionto_price_builder));
        ARROW_RETURN_NOT_OK(record.mmt_algorithmic_indicator.append(*mmt_algorithmic_indicator_builder));
        ARROW_RETURN_NOT_OK(record.mmt_publication_mode.append(*mmt_publication_mode_builder));
        ARROW_RETURN_NOT_OK(record.mmt_post_trade_deferral.append(*mmt_post_trade_deferral_builder));
        ARROW_RETURN_NOT_OK(record.mmt_duplicative_indicator.append(*mmt_duplicative_indicator_builder));
        ARROW_RETURN_NOT_OK(record.transaction_type.append(*transaction_type_builder));
        ARROW_RETURN_NOT_OK(record.effective_date_indicator.append(*effective_date_indicator_builder));
        ARROW_RETURN_NOT_OK(record.block_trade_code.append(*block_trade_code_builder));
        ARROW_RETURN_NOT_OK(record.trade_reference.append(*trade_reference_builder));
        ARROW_RETURN_NOT_OK(record.original_report_timestamp.append(*original_report_timestamp_builder));
        ARROW_RETURN_NOT_OK(record.transparency_indicator.append(*transparency_indicator_builder));
        ARROW_RETURN_NOT_OK(record.currency_coefficient.append(*currency_coefficient_builder));
        ARROW_RETURN_NOT_OK(record.price_multiplier.append(*price_multiplier_builder));
        ARROW_RETURN_NOT_OK(record.price_multiplier_decimals.append(*price_multiplier_decimals_builder));
        ARROW_RETURN_NOT_OK(record.venue.append(*venue_builder));
        ARROW_RETURN_NOT_OK(record.start_time_vwap.append(*start_time_vwap_builder));
        ARROW_RETURN_NOT_OK(record.end_time_vwap.append(*end_time_vwap_builder));
        ARROW_RETURN_NOT_OK(record.mifid_emission_allowance_type.append(*mifid_emission_allowance_type_builder));
        ARROW_RETURN_NOT_OK(record.market_of_reference_mic.append(*market_of_reference_mic_builder));
        ARROW_RETURN_NOT_OK(record.evaluated_price.append(*evaluated_price_builder));
        ARROW_RETURN_NOT_OK(record.message_price_notation.append(*message_price_notation_builder));
        ARROW_RETURN_NOT_OK(record.settlement_date.append(*settlement_date_builder));
        ARROW_RETURN_NOT_OK(record.repo_settlement_date.append(*repo_settlement_date_builder));
        ARROW_RETURN_NOT_OK(record.trade_unique_identifier.append(*trade_unique_identifier_builder));
        ARROW_RETURN_NOT_OK(record.not_used_group.append(*not_used_group_builder));
        ARROW_RETURN_NOT_OK(record.market_states_group.append(*market_states_group_builder));
        ARROW_RETURN_NOT_OK(record.emm_optional.append(*emm_optional_builder));
        ARROW_RETURN_NOT_OK(record.pattern_id.append(*pattern_id_builder));
        ARROW_RETURN_NOT_OK(record.timetables_group.append(*timetables_group_builder));
        ARROW_RETURN_NOT_OK(record.symbol_index.append(*symbol_index_builder));
        ARROW_RETURN_NOT_OK(record.optiq_segment.append(*optiq_segment_builder));
        ARROW_RETURN_NOT_OK(record.partition_id.append(*partition_id_builder));
        ARROW_RETURN_NOT_OK(record.full_instrument_name.append(*full_instrument_name_builder));
        ARROW_RETURN_NOT_OK(record.instrument_name.append(*instrument_name_builder));
        ARROW_RETURN_NOT_OK(record.instrument_trading_code.append(*instrument_trading_code_builder));
        ARROW_RETURN_NOT_OK(record.instrument_group_code.append(*instrument_group_code_builder));
        ARROW_RETURN_NOT_OK(record.isin_code.append(*isin_code_builder));
        ARROW_RETURN_NOT_OK(record.price_decimals.append(*price_decimals_builder));
        ARROW_RETURN_NOT_OK(record.quantity_decimals.append(*quantity_decimals_builder));
        ARROW_RETURN_NOT_OK(record.amount_decimals.append(*amount_decimals_builder));
        ARROW_RETURN_NOT_OK(record.ratio_decimals.append(*ratio_decimals_builder));
        ARROW_RETURN_NOT_OK(record.cfi.append(*cfi_builder));
        ARROW_RETURN_NOT_OK(record.instrument_event_date.append(*instrument_event_date_builder));
        ARROW_RETURN_NOT_OK(record.strike_price.append(*strike_price_builder));
        ARROW_RETURN_NOT_OK(record.dark_eligibility.append(*dark_eligibility_builder));
        ARROW_RETURN_NOT_OK(record.dark_lis_threshold.append(*dark_lis_threshold_builder));
        ARROW_RETURN_NOT_OK(record.dark_min_quantity.append(*dark_min_quantity_builder));
        ARROW_RETURN_NOT_OK(record.date_of_last_trade.append(*date_of_last_trade_builder));
        ARROW_RETURN_NOT_OK(record.depositary_list.append(*depositary_list_builder));
        ARROW_RETURN_NOT_OK(record.main_depositary.append(*main_depositary_builder));
        ARROW_RETURN_NOT_OK(record.first_settlement_date.append(*first_settlement_date_builder));
        ARROW_RETURN_NOT_OK(record.guarantee_indicator.append(*guarantee_indicator_builder));
        ARROW_RETURN_NOT_OK(record.icb.append(*icb_builder));
        ARROW_RETURN_NOT_OK(record.issuing_country.append(*issuing_country_builder));
        ARROW_RETURN_NOT_OK(record.last_adjusted_closing_price.append(*last_adjusted_closing_price_builder));
        ARROW_RETURN_NOT_OK(record.lot_size_optional.append(*lot_size_optional_builder));
        ARROW_RETURN_NOT_OK(record.maturity_date_optional.append(*maturity_date_optional_builder));
        ARROW_RETURN_NOT_OK(record.maximum_decimals_in_quantity.append(*maximum_decimals_in_quantity_builder));
        ARROW_RETURN_NOT_OK(record.mic.append(*mic_builder));
        ARROW_RETURN_NOT_OK(record.mic_list.append(*mic_list_builder));
        ARROW_RETURN_NOT_OK(record.country_of_exchange_optional.append(*country_of_exchange_optional_builder));
        ARROW_RETURN_NOT_OK(record.mnemonic.append(*mnemonic_builder));
        ARROW_RETURN_NOT_OK(record.underlying_mic.append(*underlying_mic_builder));
        ARROW_RETURN_NOT_OK(record.underlying_isin_code.append(*underlying_isin_code_builder));
        ARROW_RETURN_NOT_OK(record.trading_currency_optional.append(*trading_currency_optional_builder));
        ARROW_RETURN_NOT_OK(record.trading_currency_indicator.append(*trading_currency_indicator_builder));
        ARROW_RETURN_NOT_OK(record.strike_currency_indicator.append(*strike_currency_indicator_builder));
        ARROW_RETURN_NOT_OK(record.number_instrument_circulating.append(*number_instrument_circulating_builder));
        ARROW_RETURN_NOT_OK(record.par_value.append(*par_value_builder));
        ARROW_RETURN_NOT_OK(record.quantity_notation.append(*quantity_notation_builder));
        ARROW_RETURN_NOT_OK(record.inst_unit_exp.append(*inst_unit_exp_builder));
        ARROW_RETURN_NOT_OK(record.settlement_delay.append(*settlement_delay_builder));
        ARROW_RETURN_NOT_OK(record.strike_currency.append(*strike_currency_builder));
        ARROW_RETURN_NOT_OK(record.tax_code.append(*tax_code_builder));
        ARROW_RETURN_NOT_OK(record.type_of_corporate_event.append(*type_of_corporate_event_builder));
        ARROW_RETURN_NOT_OK(record.type_of_market_admission.append(*type_of_market_admission_builder));
        ARROW_RETURN_NOT_OK(record.repo_indicator.append(*repo_indicator_builder));
        ARROW_RETURN_NOT_OK(record.issue_price.append(*issue_price_builder));
        ARROW_RETURN_NOT_OK(record.nominal_currency.append(*nominal_currency_builder));
        ARROW_RETURN_NOT_OK(record.issue_price_decimals.append(*issue_price_decimals_builder));
        ARROW_RETURN_NOT_OK(record.strike_price_decimals.append(*strike_price_decimals_builder));
        ARROW_RETURN_NOT_OK(record.liquid_instrument_indicator.append(*liquid_instrument_indicator_builder));
        ARROW_RETURN_NOT_OK(record.icb_code.append(*icb_code_builder));
        ARROW_RETURN_NOT_OK(record.threshold_lis_post_trade_60mn.append(*threshold_lis_post_trade_60mn_builder));
        ARROW_RETURN_NOT_OK(record.threshold_lis_post_trade_120mn.append(*threshold_lis_post_trade_120mn_builder));
        ARROW_RETURN_NOT_OK(record.threshold_lis_post_trade_eod.append(*threshold_lis_post_trade_eod_builder));
        ARROW_RETURN_NOT_OK(record.long_mnemonic.append(*long_mnemonic_builder));
        ARROW_RETURN_NOT_OK(record.max_order_amount_call.append(*max_order_amount_call_builder));
        ARROW_RETURN_NOT_OK(record.max_order_amount_continuous.append(*max_order_amount_continuous_builder));
        ARROW_RETURN_NOT_OK(record.max_order_quantity_call.append(*max_order_quantity_call_builder));
        ARROW_RETURN_NOT_OK(record.max_order_quantity_continuous.append(*max_order_quantity_continuous_builder));
        ARROW_RETURN_NOT_OK(record.pool_factor.append(*pool_factor_builder));
        ARROW_RETURN_NOT_OK(record.emm_pattern_rep_group.append(*emm_pattern_rep_group_builder));
        ARROW_RETURN_NOT_OK(record.index_level.append(*index_level_builder));
        ARROW_RETURN_NOT_OK(record.pctg_of_capitalization.append(*pctg_of_capitalization_builder));
        ARROW_RETURN_NOT_OK(record.prct_varfrom_prev_close.append(*prct_varfrom_prev_close_builder));
        ARROW_RETURN_NOT_OK(record.num_traded_instruments.append(*num_traded_instruments_builder));
        ARROW_RETURN_NOT_OK(record.index_level_type.append(*index_level_type_builder));
        ARROW_RETURN_NOT_OK(record.index_price_code.append(*index_price_code_builder));
        ARROW_RETURN_NOT_OK(record.new_stats_group.append(*new_stats_group_builder));
        ARROW_RETURN_NOT_OK(record.opening_level.append(*opening_level_builder));
        ARROW_RETURN_NOT_OK(record.opening_time.append(*opening_time_builder));
        ARROW_RETURN_NOT_OK(record.confirmed_reference_level.append(*confirmed_reference_level_builder));
        ARROW_RETURN_NOT_OK(record.confirmed_reference_time.append(*confirmed_reference_time_builder));
        ARROW_RETURN_NOT_OK(record.closing_reference_level.append(*closing_reference_level_builder));
        ARROW_RETURN_NOT_OK(record.closing_reference_time.append(*closing_reference_time_builder));
        ARROW_RETURN_NOT_OK(record.high_level.append(*high_level_builder));
        ARROW_RETURN_NOT_OK(record.high_time.append(*high_time_builder));
        ARROW_RETURN_NOT_OK(record.low_level.append(*low_level_builder));
        ARROW_RETURN_NOT_OK(record.low_time.append(*low_time_builder));
        ARROW_RETURN_NOT_OK(record.liquidation_level.append(*liquidation_level_builder));
        ARROW_RETURN_NOT_OK(record.liquidation_time.append(*liquidation_time_builder));
        ARROW_RETURN_NOT_OK(record.derivatives_instrument_trading_code.append(*derivatives_instrument_trading_code_builder));
        ARROW_RETURN_NOT_OK(record.exchange_code.append(*exchange_code_builder));
        ARROW_RETURN_NOT_OK(record.maturity_date.append(*maturity_date_builder));
        ARROW_RETURN_NOT_OK(record.strategy_code.append(*strategy_code_builder));
        ARROW_RETURN_NOT_OK(record.contract_symbol_index.append(*contract_symbol_index_builder));
        ARROW_RETURN_NOT_OK(record.cfi_optional.append(*cfi_optional_builder));
        ARROW_RETURN_NOT_OK(record.strategy_standing_data_group.append(*strategy_standing_data_group_builder));
        ARROW_RETURN_NOT_OK(record.contract_event_date.append(*contract_event_date_builder));
        ARROW_RETURN_NOT_OK(record.exer_style.append(*exer_style_builder));
        ARROW_RETURN_NOT_OK(record.contract_name.append(*contract_name_builder));
        ARROW_RETURN_NOT_OK(record.contract_type.append(*contract_type_builder));
        ARROW_RETURN_NOT_OK(record.underlying_type.append(*underlying_type_builder));
        ARROW_RETURN_NOT_OK(record.price_decimals_optional.append(*price_decimals_optional_builder));
        ARROW_RETURN_NOT_OK(record.ratio_decimals_optional.append(*ratio_decimals_optional_builder));
        ARROW_RETURN_NOT_OK(record.country_of_exchange.append(*country_of_exchange_builder));
        ARROW_RETURN_NOT_OK(record.product_code.append(*product_code_builder));
        ARROW_RETURN_NOT_OK(record.underlying_expiry.append(*underlying_expiry_builder));
        ARROW_RETURN_NOT_OK(record.settlement_method.append(*settlement_method_builder));
        ARROW_RETURN_NOT_OK(record.trading_currency.append(*trading_currency_builder));
        ARROW_RETURN_NOT_OK(record.strike_price_decimals_ratio.append(*strike_price_decimals_ratio_builder));
        ARROW_RETURN_NOT_OK(record.contract_trading_type.append(*contract_trading_type_builder));
        ARROW_RETURN_NOT_OK(record.underlying_subtype.append(*underlying_subtype_builder));
        ARROW_RETURN_NOT_OK(record.mother_stock_isin.append(*mother_stock_isin_builder));
        ARROW_RETURN_NOT_OK(record.settlement_tick_size.append(*settlement_tick_size_builder));
        ARROW_RETURN_NOT_OK(record.edsp_tick_size.append(*edsp_tick_size_builder));
        ARROW_RETURN_NOT_OK(record.underlying_symbol_index.append(*underlying_symbol_index_builder));
        ARROW_RETURN_NOT_OK(record.trading_policy.append(*trading_policy_builder));
        ARROW_RETURN_NOT_OK(record.reference_spread_table_id.append(*reference_spread_table_id_builder));
        ARROW_RETURN_NOT_OK(record.derivatives_market_model.append(*derivatives_market_model_builder));
        ARROW_RETURN_NOT_OK(record.trading_unit.append(*trading_unit_builder));
        ARROW_RETURN_NOT_OK(record.reference_price_origin_in_opening_call.append(*reference_price_origin_in_opening_call_builder));
        ARROW_RETURN_NOT_OK(record.reference_price_origin_in_continuous.append(*reference_price_origin_in_continuous_builder));
        ARROW_RETURN_NOT_OK(record.reference_price_origin_in_trading_interruption.append(*reference_price_origin_in_trading_interruption_builder));
        ARROW_RETURN_NOT_OK(record.collar_expansion_factor.append(*collar_expansion_factor_builder));
        ARROW_RETURN_NOT_OK(record.mifidii_liquid_flag.append(*mifidii_liquid_flag_builder));
        ARROW_RETURN_NOT_OK(record.pricing_algorithm.append(*pricing_algorithm_builder));
        ARROW_RETURN_NOT_OK(record.contract_emm_properties_group.append(*contract_emm_properties_group_builder));
        ARROW_RETURN_NOT_OK(record.lot_size.append(*lot_size_builder));
        ARROW_RETURN_NOT_OK(record.last_trading_date.append(*last_trading_date_builder));
        ARROW_RETURN_NOT_OK(record.days_to_expiry.append(*days_to_expiry_builder));
        ARROW_RETURN_NOT_OK(record.derivatives_instrument_trading_code_optional.append(*derivatives_instrument_trading_code_optional_builder));
        ARROW_RETURN_NOT_OK(record.derivatives_instrument_type.append(*derivatives_instrument_type_builder));
        ARROW_RETURN_NOT_OK(record.expiry_cycle_type.append(*expiry_cycle_type_builder));
        ARROW_RETURN_NOT_OK(record.underlying_derivatives_instrument_trading_code.append(*underlying_derivatives_instrument_trading_code_builder));
        ARROW_RETURN_NOT_OK(record.outright_rep_group.append(*outright_rep_group_builder));
        ARROW_RETURN_NOT_OK(record.long_order_updates_group.append(*long_order_updates_group_builder));
        ARROW_RETURN_NOT_OK(record.package_components_group.append(*package_components_group_builder));
        ARROW_RETURN_NOT_OK(record.mifid_instrument_id_type.append(*mifid_instrument_id_type_builder));
        ARROW_RETURN_NOT_OK(record.mifid_instrument_id.append(*mifid_instrument_id_builder));
        ARROW_RETURN_NOT_OK(record.currency.append(*currency_builder));
        ARROW_RETURN_NOT_OK(record.lei_code.append(*lei_code_builder));
        ARROW_RETURN_NOT_OK(record.quote_update_type.append(*quote_update_type_builder));
        ARROW_RETURN_NOT_OK(record.mifid_price.append(*mifid_price_builder));
        ARROW_RETURN_NOT_OK(record.apa_origin.append(*apa_origin_builder));
        ARROW_RETURN_NOT_OK(record.second_notional_currency.append(*second_notional_currency_builder));
        ARROW_RETURN_NOT_OK(record.underlying_index_name.append(*underlying_index_name_builder));
        ARROW_RETURN_NOT_OK(record.underlying_index_term.append(*underlying_index_term_builder));
        ARROW_RETURN_NOT_OK(record.option_type.append(*option_type_builder));
        ARROW_RETURN_NOT_OK(record.expiry_date.append(*expiry_date_builder));
        ARROW_RETURN_NOT_OK(record.mifid_transaction_id.append(*mifid_transaction_id_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_market_mechanism.append(*efficient_mmt_market_mechanism_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_trading_mode.append(*efficient_mmt_trading_mode_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_transaction_category.append(*efficient_mmt_transaction_category_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_negotiation_indicator.append(*efficient_mmt_negotiation_indicator_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_agency_cross_trade_indicator.append(*efficient_mmt_agency_cross_trade_indicator_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_modification_indicator.append(*efficient_mmt_modification_indicator_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_benchmark_indicator.append(*efficient_mmt_benchmark_indicator_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_special_dividend_indicator.append(*efficient_mmt_special_dividend_indicator_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_off_book_automated_indicator.append(*efficient_mmt_off_book_automated_indicator_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_contributionto_price.append(*efficient_mmt_contributionto_price_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_algorithmic_indicator.append(*efficient_mmt_algorithmic_indicator_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_publication_mode.append(*efficient_mmt_publication_mode_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_post_trade_deferral.append(*efficient_mmt_post_trade_deferral_builder));
        ARROW_RETURN_NOT_OK(record.efficient_mmt_duplicative_indicator.append(*efficient_mmt_duplicative_indicator_builder));
        ARROW_RETURN_NOT_OK(record.long_trade_reference.append(*long_trade_reference_builder));
        ARROW_RETURN_NOT_OK(record.isin_code_optional.append(*isin_code_optional_builder));
        ARROW_RETURN_NOT_OK(record.sedol_code.append(*sedol_code_builder));
        ARROW_RETURN_NOT_OK(record.long_issuer_name.append(*long_issuer_name_builder));
        ARROW_RETURN_NOT_OK(record.long_instrument_name.append(*long_instrument_name_builder));
        ARROW_RETURN_NOT_OK(record.currency_optional.append(*currency_optional_builder));
        ARROW_RETURN_NOT_OK(record.date_of_initial_listing.append(*date_of_initial_listing_builder));
        ARROW_RETURN_NOT_OK(record.share_amount_in_issue.append(*share_amount_in_issue_builder));
        ARROW_RETURN_NOT_OK(record.opened_closed_fund.append(*opened_closed_fund_builder));
        ARROW_RETURN_NOT_OK(record.last_nav_price.append(*last_nav_price_builder));
        ARROW_RETURN_NOT_OK(record.gross_of_cdsc_indicator.append(*gross_of_cdsc_indicator_builder));
        ARROW_RETURN_NOT_OK(record.coupon.append(*coupon_builder));
        ARROW_RETURN_NOT_OK(record.closing_price.append(*closing_price_builder));
        ARROW_RETURN_NOT_OK(record.mic_optional.append(*mic_optional_builder));
        ARROW_RETURN_NOT_OK(record.gross_dividend_payable_per_unit.append(*gross_dividend_payable_per_unit_builder));
        ARROW_RETURN_NOT_OK(record.dividend_currency.append(*dividend_currency_builder));
        ARROW_RETURN_NOT_OK(record.dividend_record_date.append(*dividend_record_date_builder));
        ARROW_RETURN_NOT_OK(record.dividend_rate.append(*dividend_rate_builder));
        ARROW_RETURN_NOT_OK(record.ex_dividend_date.append(*ex_dividend_date_builder));
        ARROW_RETURN_NOT_OK(record.dividend_payment_date.append(*dividend_payment_date_builder));
        ARROW_RETURN_NOT_OK(record.tax_description_attaching_to_a_dividend.append(*tax_description_attaching_to_a_dividend_builder));
        ARROW_RETURN_NOT_OK(record.next_meeting.append(*next_meeting_builder));
        ARROW_RETURN_NOT_OK(record.gross_dividend_in_euros.append(*gross_dividend_in_euros_builder));
        ARROW_RETURN_NOT_OK(record.issue_date.append(*issue_date_builder));
        ARROW_RETURN_NOT_OK(record.payment_frequency.append(*payment_frequency_builder));
        ARROW_RETURN_NOT_OK(record.minimum_amount.append(*minimum_amount_builder));
        ARROW_RETURN_NOT_OK(record.instrument_category.append(*instrument_category_builder));
        ARROW_RETURN_NOT_OK(record.security_condition.append(*security_condition_builder));
        ARROW_RETURN_NOT_OK(record.price_index_level_decimals.append(*price_index_level_decimals_builder));
        ARROW_RETURN_NOT_OK(record.ratio_multiplier_decimals.append(*ratio_multiplier_decimals_builder));
        ARROW_RETURN_NOT_OK(record.interest_payment_date_rep_group.append(*interest_payment_date_rep_group_builder));
        ARROW_RETURN_NOT_OK(record.bid_offer_date_time.append(*bid_offer_date_time_builder));
        ARROW_RETURN_NOT_OK(record.mmt_modification_indicator.append(*mmt_modification_indicator_builder));
        ARROW_RETURN_NOT_OK(record.price.append(*price_builder));
        ARROW_RETURN_NOT_OK(record.bid_price.append(*bid_price_builder));
        ARROW_RETURN_NOT_OK(record.offer_price.append(*offer_price_builder));
        ARROW_RETURN_NOT_OK(record.quantity.append(*quantity_builder));
        ARROW_RETURN_NOT_OK(record.notional_amount_traded.append(*notional_amount_traded_builder));
        ARROW_RETURN_NOT_OK(record.nav_price.append(*nav_price_builder));
        ARROW_RETURN_NOT_OK(record.event_time_optional.append(*event_time_optional_builder));
        ARROW_RETURN_NOT_OK(record.nav_bid_price.append(*nav_bid_price_builder));
        ARROW_RETURN_NOT_OK(record.nav_offer_price.append(*nav_offer_price_builder));
        ARROW_RETURN_NOT_OK(record.last_md_seq_num.append(*last_md_seq_num_builder));
        ARROW_RETURN_NOT_OK(record.snapshot_time.append(*snapshot_time_builder));

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
        std::shared_ptr<arrow::Array> md_seq_num_column;
        std::shared_ptr<arrow::Array> session_trading_day_column;
        std::shared_ptr<arrow::Array> event_time_column;
        std::shared_ptr<arrow::Array> md_seq_num_optional_column;
        std::shared_ptr<arrow::Array> technical_notification_type_column;
        std::shared_ptr<arrow::Array> rebroadcast_indicator_column;
        std::shared_ptr<arrow::Array> retransmission_start_time_column;
        std::shared_ptr<arrow::Array> retransmission_end_time_column;
        std::shared_ptr<arrow::Array> symbol_index_optional_column;
        std::shared_ptr<arrow::Array> emm_column;
        std::shared_ptr<arrow::Array> block_length_short_column;
        std::shared_ptr<arrow::Array> num_in_group_column;
        std::shared_ptr<arrow::Array> market_updates_group_column;
        std::shared_ptr<arrow::Array> order_updates_group_column;
        std::shared_ptr<arrow::Array> price_updates_group_column;
        std::shared_ptr<arrow::Array> trading_date_time_column;
        std::shared_ptr<arrow::Array> publication_date_time_column;
        std::shared_ptr<arrow::Array> trade_type_column;
        std::shared_ptr<arrow::Array> mifid_instrument_id_type_optional_column;
        std::shared_ptr<arrow::Array> mifid_instrument_id_optional_column;
        std::shared_ptr<arrow::Array> mifid_execution_id_column;
        std::shared_ptr<arrow::Array> mifid_price_optional_column;
        std::shared_ptr<arrow::Array> mifid_quantity_column;
        std::shared_ptr<arrow::Array> mifid_price_notation_column;
        std::shared_ptr<arrow::Array> mifid_currency_column;
        std::shared_ptr<arrow::Array> mifid_qty_in_msrmt_unit_notation_column;
        std::shared_ptr<arrow::Array> mifid_quantity_measurement_unit_column;
        std::shared_ptr<arrow::Array> mifid_notional_amount_column;
        std::shared_ptr<arrow::Array> notional_currency_column;
        std::shared_ptr<arrow::Array> mifid_clearing_flag_column;
        std::shared_ptr<arrow::Array> mmt_market_mechanism_column;
        std::shared_ptr<arrow::Array> mmt_trading_mode_column;
        std::shared_ptr<arrow::Array> mmt_transaction_category_column;
        std::shared_ptr<arrow::Array> mmt_negotiation_indicator_column;
        std::shared_ptr<arrow::Array> mmt_agency_cross_trade_indicator_column;
        std::shared_ptr<arrow::Array> mmt_modification_indicator_char_4_optional_column;
        std::shared_ptr<arrow::Array> mmt_benchmark_indicator_column;
        std::shared_ptr<arrow::Array> mmt_special_dividend_indicator_column;
        std::shared_ptr<arrow::Array> mmt_off_book_automated_indicator_column;
        std::shared_ptr<arrow::Array> mmt_contributionto_price_column;
        std::shared_ptr<arrow::Array> mmt_algorithmic_indicator_column;
        std::shared_ptr<arrow::Array> mmt_publication_mode_column;
        std::shared_ptr<arrow::Array> mmt_post_trade_deferral_column;
        std::shared_ptr<arrow::Array> mmt_duplicative_indicator_column;
        std::shared_ptr<arrow::Array> transaction_type_column;
        std::shared_ptr<arrow::Array> effective_date_indicator_column;
        std::shared_ptr<arrow::Array> block_trade_code_column;
        std::shared_ptr<arrow::Array> trade_reference_column;
        std::shared_ptr<arrow::Array> original_report_timestamp_column;
        std::shared_ptr<arrow::Array> transparency_indicator_column;
        std::shared_ptr<arrow::Array> currency_coefficient_column;
        std::shared_ptr<arrow::Array> price_multiplier_column;
        std::shared_ptr<arrow::Array> price_multiplier_decimals_column;
        std::shared_ptr<arrow::Array> venue_column;
        std::shared_ptr<arrow::Array> start_time_vwap_column;
        std::shared_ptr<arrow::Array> end_time_vwap_column;
        std::shared_ptr<arrow::Array> mifid_emission_allowance_type_column;
        std::shared_ptr<arrow::Array> market_of_reference_mic_column;
        std::shared_ptr<arrow::Array> evaluated_price_column;
        std::shared_ptr<arrow::Array> message_price_notation_column;
        std::shared_ptr<arrow::Array> settlement_date_column;
        std::shared_ptr<arrow::Array> repo_settlement_date_column;
        std::shared_ptr<arrow::Array> trade_unique_identifier_column;
        std::shared_ptr<arrow::Array> not_used_group_column;
        std::shared_ptr<arrow::Array> market_states_group_column;
        std::shared_ptr<arrow::Array> emm_optional_column;
        std::shared_ptr<arrow::Array> pattern_id_column;
        std::shared_ptr<arrow::Array> timetables_group_column;
        std::shared_ptr<arrow::Array> symbol_index_column;
        std::shared_ptr<arrow::Array> optiq_segment_column;
        std::shared_ptr<arrow::Array> partition_id_column;
        std::shared_ptr<arrow::Array> full_instrument_name_column;
        std::shared_ptr<arrow::Array> instrument_name_column;
        std::shared_ptr<arrow::Array> instrument_trading_code_column;
        std::shared_ptr<arrow::Array> instrument_group_code_column;
        std::shared_ptr<arrow::Array> isin_code_column;
        std::shared_ptr<arrow::Array> price_decimals_column;
        std::shared_ptr<arrow::Array> quantity_decimals_column;
        std::shared_ptr<arrow::Array> amount_decimals_column;
        std::shared_ptr<arrow::Array> ratio_decimals_column;
        std::shared_ptr<arrow::Array> cfi_column;
        std::shared_ptr<arrow::Array> instrument_event_date_column;
        std::shared_ptr<arrow::Array> strike_price_column;
        std::shared_ptr<arrow::Array> dark_eligibility_column;
        std::shared_ptr<arrow::Array> dark_lis_threshold_column;
        std::shared_ptr<arrow::Array> dark_min_quantity_column;
        std::shared_ptr<arrow::Array> date_of_last_trade_column;
        std::shared_ptr<arrow::Array> depositary_list_column;
        std::shared_ptr<arrow::Array> main_depositary_column;
        std::shared_ptr<arrow::Array> first_settlement_date_column;
        std::shared_ptr<arrow::Array> guarantee_indicator_column;
        std::shared_ptr<arrow::Array> icb_column;
        std::shared_ptr<arrow::Array> issuing_country_column;
        std::shared_ptr<arrow::Array> last_adjusted_closing_price_column;
        std::shared_ptr<arrow::Array> lot_size_optional_column;
        std::shared_ptr<arrow::Array> maturity_date_optional_column;
        std::shared_ptr<arrow::Array> maximum_decimals_in_quantity_column;
        std::shared_ptr<arrow::Array> mic_column;
        std::shared_ptr<arrow::Array> mic_list_column;
        std::shared_ptr<arrow::Array> country_of_exchange_optional_column;
        std::shared_ptr<arrow::Array> mnemonic_column;
        std::shared_ptr<arrow::Array> underlying_mic_column;
        std::shared_ptr<arrow::Array> underlying_isin_code_column;
        std::shared_ptr<arrow::Array> trading_currency_optional_column;
        std::shared_ptr<arrow::Array> trading_currency_indicator_column;
        std::shared_ptr<arrow::Array> strike_currency_indicator_column;
        std::shared_ptr<arrow::Array> number_instrument_circulating_column;
        std::shared_ptr<arrow::Array> par_value_column;
        std::shared_ptr<arrow::Array> quantity_notation_column;
        std::shared_ptr<arrow::Array> inst_unit_exp_column;
        std::shared_ptr<arrow::Array> settlement_delay_column;
        std::shared_ptr<arrow::Array> strike_currency_column;
        std::shared_ptr<arrow::Array> tax_code_column;
        std::shared_ptr<arrow::Array> type_of_corporate_event_column;
        std::shared_ptr<arrow::Array> type_of_market_admission_column;
        std::shared_ptr<arrow::Array> repo_indicator_column;
        std::shared_ptr<arrow::Array> issue_price_column;
        std::shared_ptr<arrow::Array> nominal_currency_column;
        std::shared_ptr<arrow::Array> issue_price_decimals_column;
        std::shared_ptr<arrow::Array> strike_price_decimals_column;
        std::shared_ptr<arrow::Array> liquid_instrument_indicator_column;
        std::shared_ptr<arrow::Array> icb_code_column;
        std::shared_ptr<arrow::Array> threshold_lis_post_trade_60mn_column;
        std::shared_ptr<arrow::Array> threshold_lis_post_trade_120mn_column;
        std::shared_ptr<arrow::Array> threshold_lis_post_trade_eod_column;
        std::shared_ptr<arrow::Array> long_mnemonic_column;
        std::shared_ptr<arrow::Array> max_order_amount_call_column;
        std::shared_ptr<arrow::Array> max_order_amount_continuous_column;
        std::shared_ptr<arrow::Array> max_order_quantity_call_column;
        std::shared_ptr<arrow::Array> max_order_quantity_continuous_column;
        std::shared_ptr<arrow::Array> pool_factor_column;
        std::shared_ptr<arrow::Array> emm_pattern_rep_group_column;
        std::shared_ptr<arrow::Array> index_level_column;
        std::shared_ptr<arrow::Array> pctg_of_capitalization_column;
        std::shared_ptr<arrow::Array> prct_varfrom_prev_close_column;
        std::shared_ptr<arrow::Array> num_traded_instruments_column;
        std::shared_ptr<arrow::Array> index_level_type_column;
        std::shared_ptr<arrow::Array> index_price_code_column;
        std::shared_ptr<arrow::Array> new_stats_group_column;
        std::shared_ptr<arrow::Array> opening_level_column;
        std::shared_ptr<arrow::Array> opening_time_column;
        std::shared_ptr<arrow::Array> confirmed_reference_level_column;
        std::shared_ptr<arrow::Array> confirmed_reference_time_column;
        std::shared_ptr<arrow::Array> closing_reference_level_column;
        std::shared_ptr<arrow::Array> closing_reference_time_column;
        std::shared_ptr<arrow::Array> high_level_column;
        std::shared_ptr<arrow::Array> high_time_column;
        std::shared_ptr<arrow::Array> low_level_column;
        std::shared_ptr<arrow::Array> low_time_column;
        std::shared_ptr<arrow::Array> liquidation_level_column;
        std::shared_ptr<arrow::Array> liquidation_time_column;
        std::shared_ptr<arrow::Array> derivatives_instrument_trading_code_column;
        std::shared_ptr<arrow::Array> exchange_code_column;
        std::shared_ptr<arrow::Array> maturity_date_column;
        std::shared_ptr<arrow::Array> strategy_code_column;
        std::shared_ptr<arrow::Array> contract_symbol_index_column;
        std::shared_ptr<arrow::Array> cfi_optional_column;
        std::shared_ptr<arrow::Array> strategy_standing_data_group_column;
        std::shared_ptr<arrow::Array> contract_event_date_column;
        std::shared_ptr<arrow::Array> exer_style_column;
        std::shared_ptr<arrow::Array> contract_name_column;
        std::shared_ptr<arrow::Array> contract_type_column;
        std::shared_ptr<arrow::Array> underlying_type_column;
        std::shared_ptr<arrow::Array> price_decimals_optional_column;
        std::shared_ptr<arrow::Array> ratio_decimals_optional_column;
        std::shared_ptr<arrow::Array> country_of_exchange_column;
        std::shared_ptr<arrow::Array> product_code_column;
        std::shared_ptr<arrow::Array> underlying_expiry_column;
        std::shared_ptr<arrow::Array> settlement_method_column;
        std::shared_ptr<arrow::Array> trading_currency_column;
        std::shared_ptr<arrow::Array> strike_price_decimals_ratio_column;
        std::shared_ptr<arrow::Array> contract_trading_type_column;
        std::shared_ptr<arrow::Array> underlying_subtype_column;
        std::shared_ptr<arrow::Array> mother_stock_isin_column;
        std::shared_ptr<arrow::Array> settlement_tick_size_column;
        std::shared_ptr<arrow::Array> edsp_tick_size_column;
        std::shared_ptr<arrow::Array> underlying_symbol_index_column;
        std::shared_ptr<arrow::Array> trading_policy_column;
        std::shared_ptr<arrow::Array> reference_spread_table_id_column;
        std::shared_ptr<arrow::Array> derivatives_market_model_column;
        std::shared_ptr<arrow::Array> trading_unit_column;
        std::shared_ptr<arrow::Array> reference_price_origin_in_opening_call_column;
        std::shared_ptr<arrow::Array> reference_price_origin_in_continuous_column;
        std::shared_ptr<arrow::Array> reference_price_origin_in_trading_interruption_column;
        std::shared_ptr<arrow::Array> collar_expansion_factor_column;
        std::shared_ptr<arrow::Array> mifidii_liquid_flag_column;
        std::shared_ptr<arrow::Array> pricing_algorithm_column;
        std::shared_ptr<arrow::Array> contract_emm_properties_group_column;
        std::shared_ptr<arrow::Array> lot_size_column;
        std::shared_ptr<arrow::Array> last_trading_date_column;
        std::shared_ptr<arrow::Array> days_to_expiry_column;
        std::shared_ptr<arrow::Array> derivatives_instrument_trading_code_optional_column;
        std::shared_ptr<arrow::Array> derivatives_instrument_type_column;
        std::shared_ptr<arrow::Array> expiry_cycle_type_column;
        std::shared_ptr<arrow::Array> underlying_derivatives_instrument_trading_code_column;
        std::shared_ptr<arrow::Array> outright_rep_group_column;
        std::shared_ptr<arrow::Array> long_order_updates_group_column;
        std::shared_ptr<arrow::Array> package_components_group_column;
        std::shared_ptr<arrow::Array> mifid_instrument_id_type_column;
        std::shared_ptr<arrow::Array> mifid_instrument_id_column;
        std::shared_ptr<arrow::Array> currency_column;
        std::shared_ptr<arrow::Array> lei_code_column;
        std::shared_ptr<arrow::Array> quote_update_type_column;
        std::shared_ptr<arrow::Array> mifid_price_column;
        std::shared_ptr<arrow::Array> apa_origin_column;
        std::shared_ptr<arrow::Array> second_notional_currency_column;
        std::shared_ptr<arrow::Array> underlying_index_name_column;
        std::shared_ptr<arrow::Array> underlying_index_term_column;
        std::shared_ptr<arrow::Array> option_type_column;
        std::shared_ptr<arrow::Array> expiry_date_column;
        std::shared_ptr<arrow::Array> mifid_transaction_id_column;
        std::shared_ptr<arrow::Array> efficient_mmt_market_mechanism_column;
        std::shared_ptr<arrow::Array> efficient_mmt_trading_mode_column;
        std::shared_ptr<arrow::Array> efficient_mmt_transaction_category_column;
        std::shared_ptr<arrow::Array> efficient_mmt_negotiation_indicator_column;
        std::shared_ptr<arrow::Array> efficient_mmt_agency_cross_trade_indicator_column;
        std::shared_ptr<arrow::Array> efficient_mmt_modification_indicator_column;
        std::shared_ptr<arrow::Array> efficient_mmt_benchmark_indicator_column;
        std::shared_ptr<arrow::Array> efficient_mmt_special_dividend_indicator_column;
        std::shared_ptr<arrow::Array> efficient_mmt_off_book_automated_indicator_column;
        std::shared_ptr<arrow::Array> efficient_mmt_contributionto_price_column;
        std::shared_ptr<arrow::Array> efficient_mmt_algorithmic_indicator_column;
        std::shared_ptr<arrow::Array> efficient_mmt_publication_mode_column;
        std::shared_ptr<arrow::Array> efficient_mmt_post_trade_deferral_column;
        std::shared_ptr<arrow::Array> efficient_mmt_duplicative_indicator_column;
        std::shared_ptr<arrow::Array> long_trade_reference_column;
        std::shared_ptr<arrow::Array> isin_code_optional_column;
        std::shared_ptr<arrow::Array> sedol_code_column;
        std::shared_ptr<arrow::Array> long_issuer_name_column;
        std::shared_ptr<arrow::Array> long_instrument_name_column;
        std::shared_ptr<arrow::Array> currency_optional_column;
        std::shared_ptr<arrow::Array> date_of_initial_listing_column;
        std::shared_ptr<arrow::Array> share_amount_in_issue_column;
        std::shared_ptr<arrow::Array> opened_closed_fund_column;
        std::shared_ptr<arrow::Array> last_nav_price_column;
        std::shared_ptr<arrow::Array> gross_of_cdsc_indicator_column;
        std::shared_ptr<arrow::Array> coupon_column;
        std::shared_ptr<arrow::Array> closing_price_column;
        std::shared_ptr<arrow::Array> mic_optional_column;
        std::shared_ptr<arrow::Array> gross_dividend_payable_per_unit_column;
        std::shared_ptr<arrow::Array> dividend_currency_column;
        std::shared_ptr<arrow::Array> dividend_record_date_column;
        std::shared_ptr<arrow::Array> dividend_rate_column;
        std::shared_ptr<arrow::Array> ex_dividend_date_column;
        std::shared_ptr<arrow::Array> dividend_payment_date_column;
        std::shared_ptr<arrow::Array> tax_description_attaching_to_a_dividend_column;
        std::shared_ptr<arrow::Array> next_meeting_column;
        std::shared_ptr<arrow::Array> gross_dividend_in_euros_column;
        std::shared_ptr<arrow::Array> issue_date_column;
        std::shared_ptr<arrow::Array> payment_frequency_column;
        std::shared_ptr<arrow::Array> minimum_amount_column;
        std::shared_ptr<arrow::Array> instrument_category_column;
        std::shared_ptr<arrow::Array> security_condition_column;
        std::shared_ptr<arrow::Array> price_index_level_decimals_column;
        std::shared_ptr<arrow::Array> ratio_multiplier_decimals_column;
        std::shared_ptr<arrow::Array> interest_payment_date_rep_group_column;
        std::shared_ptr<arrow::Array> bid_offer_date_time_column;
        std::shared_ptr<arrow::Array> mmt_modification_indicator_column;
        std::shared_ptr<arrow::Array> price_column;
        std::shared_ptr<arrow::Array> bid_price_column;
        std::shared_ptr<arrow::Array> offer_price_column;
        std::shared_ptr<arrow::Array> quantity_column;
        std::shared_ptr<arrow::Array> notional_amount_traded_column;
        std::shared_ptr<arrow::Array> nav_price_column;
        std::shared_ptr<arrow::Array> event_time_optional_column;
        std::shared_ptr<arrow::Array> nav_bid_price_column;
        std::shared_ptr<arrow::Array> nav_offer_price_column;
        std::shared_ptr<arrow::Array> last_md_seq_num_column;
        std::shared_ptr<arrow::Array> snapshot_time_column;

        ARROW_RETURN_NOT_OK(event_type_builder->Finish(&event_type_column));
        ARROW_RETURN_NOT_OK(md_seq_num_builder->Finish(&md_seq_num_column));
        ARROW_RETURN_NOT_OK(session_trading_day_builder->Finish(&session_trading_day_column));
        ARROW_RETURN_NOT_OK(event_time_builder->Finish(&event_time_column));
        ARROW_RETURN_NOT_OK(md_seq_num_optional_builder->Finish(&md_seq_num_optional_column));
        ARROW_RETURN_NOT_OK(technical_notification_type_builder->Finish(&technical_notification_type_column));
        ARROW_RETURN_NOT_OK(rebroadcast_indicator_builder->Finish(&rebroadcast_indicator_column));
        ARROW_RETURN_NOT_OK(retransmission_start_time_builder->Finish(&retransmission_start_time_column));
        ARROW_RETURN_NOT_OK(retransmission_end_time_builder->Finish(&retransmission_end_time_column));
        ARROW_RETURN_NOT_OK(symbol_index_optional_builder->Finish(&symbol_index_optional_column));
        ARROW_RETURN_NOT_OK(emm_builder->Finish(&emm_column));
        ARROW_RETURN_NOT_OK(block_length_short_builder->Finish(&block_length_short_column));
        ARROW_RETURN_NOT_OK(num_in_group_builder->Finish(&num_in_group_column));
        ARROW_RETURN_NOT_OK(market_updates_group_builder->Finish(&market_updates_group_column));
        ARROW_RETURN_NOT_OK(order_updates_group_builder->Finish(&order_updates_group_column));
        ARROW_RETURN_NOT_OK(price_updates_group_builder->Finish(&price_updates_group_column));
        ARROW_RETURN_NOT_OK(trading_date_time_builder->Finish(&trading_date_time_column));
        ARROW_RETURN_NOT_OK(publication_date_time_builder->Finish(&publication_date_time_column));
        ARROW_RETURN_NOT_OK(trade_type_builder->Finish(&trade_type_column));
        ARROW_RETURN_NOT_OK(mifid_instrument_id_type_optional_builder->Finish(&mifid_instrument_id_type_optional_column));
        ARROW_RETURN_NOT_OK(mifid_instrument_id_optional_builder->Finish(&mifid_instrument_id_optional_column));
        ARROW_RETURN_NOT_OK(mifid_execution_id_builder->Finish(&mifid_execution_id_column));
        ARROW_RETURN_NOT_OK(mifid_price_optional_builder->Finish(&mifid_price_optional_column));
        ARROW_RETURN_NOT_OK(mifid_quantity_builder->Finish(&mifid_quantity_column));
        ARROW_RETURN_NOT_OK(mifid_price_notation_builder->Finish(&mifid_price_notation_column));
        ARROW_RETURN_NOT_OK(mifid_currency_builder->Finish(&mifid_currency_column));
        ARROW_RETURN_NOT_OK(mifid_qty_in_msrmt_unit_notation_builder->Finish(&mifid_qty_in_msrmt_unit_notation_column));
        ARROW_RETURN_NOT_OK(mifid_quantity_measurement_unit_builder->Finish(&mifid_quantity_measurement_unit_column));
        ARROW_RETURN_NOT_OK(mifid_notional_amount_builder->Finish(&mifid_notional_amount_column));
        ARROW_RETURN_NOT_OK(notional_currency_builder->Finish(&notional_currency_column));
        ARROW_RETURN_NOT_OK(mifid_clearing_flag_builder->Finish(&mifid_clearing_flag_column));
        ARROW_RETURN_NOT_OK(mmt_market_mechanism_builder->Finish(&mmt_market_mechanism_column));
        ARROW_RETURN_NOT_OK(mmt_trading_mode_builder->Finish(&mmt_trading_mode_column));
        ARROW_RETURN_NOT_OK(mmt_transaction_category_builder->Finish(&mmt_transaction_category_column));
        ARROW_RETURN_NOT_OK(mmt_negotiation_indicator_builder->Finish(&mmt_negotiation_indicator_column));
        ARROW_RETURN_NOT_OK(mmt_agency_cross_trade_indicator_builder->Finish(&mmt_agency_cross_trade_indicator_column));
        ARROW_RETURN_NOT_OK(mmt_modification_indicator_char_4_optional_builder->Finish(&mmt_modification_indicator_char_4_optional_column));
        ARROW_RETURN_NOT_OK(mmt_benchmark_indicator_builder->Finish(&mmt_benchmark_indicator_column));
        ARROW_RETURN_NOT_OK(mmt_special_dividend_indicator_builder->Finish(&mmt_special_dividend_indicator_column));
        ARROW_RETURN_NOT_OK(mmt_off_book_automated_indicator_builder->Finish(&mmt_off_book_automated_indicator_column));
        ARROW_RETURN_NOT_OK(mmt_contributionto_price_builder->Finish(&mmt_contributionto_price_column));
        ARROW_RETURN_NOT_OK(mmt_algorithmic_indicator_builder->Finish(&mmt_algorithmic_indicator_column));
        ARROW_RETURN_NOT_OK(mmt_publication_mode_builder->Finish(&mmt_publication_mode_column));
        ARROW_RETURN_NOT_OK(mmt_post_trade_deferral_builder->Finish(&mmt_post_trade_deferral_column));
        ARROW_RETURN_NOT_OK(mmt_duplicative_indicator_builder->Finish(&mmt_duplicative_indicator_column));
        ARROW_RETURN_NOT_OK(transaction_type_builder->Finish(&transaction_type_column));
        ARROW_RETURN_NOT_OK(effective_date_indicator_builder->Finish(&effective_date_indicator_column));
        ARROW_RETURN_NOT_OK(block_trade_code_builder->Finish(&block_trade_code_column));
        ARROW_RETURN_NOT_OK(trade_reference_builder->Finish(&trade_reference_column));
        ARROW_RETURN_NOT_OK(original_report_timestamp_builder->Finish(&original_report_timestamp_column));
        ARROW_RETURN_NOT_OK(transparency_indicator_builder->Finish(&transparency_indicator_column));
        ARROW_RETURN_NOT_OK(currency_coefficient_builder->Finish(&currency_coefficient_column));
        ARROW_RETURN_NOT_OK(price_multiplier_builder->Finish(&price_multiplier_column));
        ARROW_RETURN_NOT_OK(price_multiplier_decimals_builder->Finish(&price_multiplier_decimals_column));
        ARROW_RETURN_NOT_OK(venue_builder->Finish(&venue_column));
        ARROW_RETURN_NOT_OK(start_time_vwap_builder->Finish(&start_time_vwap_column));
        ARROW_RETURN_NOT_OK(end_time_vwap_builder->Finish(&end_time_vwap_column));
        ARROW_RETURN_NOT_OK(mifid_emission_allowance_type_builder->Finish(&mifid_emission_allowance_type_column));
        ARROW_RETURN_NOT_OK(market_of_reference_mic_builder->Finish(&market_of_reference_mic_column));
        ARROW_RETURN_NOT_OK(evaluated_price_builder->Finish(&evaluated_price_column));
        ARROW_RETURN_NOT_OK(message_price_notation_builder->Finish(&message_price_notation_column));
        ARROW_RETURN_NOT_OK(settlement_date_builder->Finish(&settlement_date_column));
        ARROW_RETURN_NOT_OK(repo_settlement_date_builder->Finish(&repo_settlement_date_column));
        ARROW_RETURN_NOT_OK(trade_unique_identifier_builder->Finish(&trade_unique_identifier_column));
        ARROW_RETURN_NOT_OK(not_used_group_builder->Finish(&not_used_group_column));
        ARROW_RETURN_NOT_OK(market_states_group_builder->Finish(&market_states_group_column));
        ARROW_RETURN_NOT_OK(emm_optional_builder->Finish(&emm_optional_column));
        ARROW_RETURN_NOT_OK(pattern_id_builder->Finish(&pattern_id_column));
        ARROW_RETURN_NOT_OK(timetables_group_builder->Finish(&timetables_group_column));
        ARROW_RETURN_NOT_OK(symbol_index_builder->Finish(&symbol_index_column));
        ARROW_RETURN_NOT_OK(optiq_segment_builder->Finish(&optiq_segment_column));
        ARROW_RETURN_NOT_OK(partition_id_builder->Finish(&partition_id_column));
        ARROW_RETURN_NOT_OK(full_instrument_name_builder->Finish(&full_instrument_name_column));
        ARROW_RETURN_NOT_OK(instrument_name_builder->Finish(&instrument_name_column));
        ARROW_RETURN_NOT_OK(instrument_trading_code_builder->Finish(&instrument_trading_code_column));
        ARROW_RETURN_NOT_OK(instrument_group_code_builder->Finish(&instrument_group_code_column));
        ARROW_RETURN_NOT_OK(isin_code_builder->Finish(&isin_code_column));
        ARROW_RETURN_NOT_OK(price_decimals_builder->Finish(&price_decimals_column));
        ARROW_RETURN_NOT_OK(quantity_decimals_builder->Finish(&quantity_decimals_column));
        ARROW_RETURN_NOT_OK(amount_decimals_builder->Finish(&amount_decimals_column));
        ARROW_RETURN_NOT_OK(ratio_decimals_builder->Finish(&ratio_decimals_column));
        ARROW_RETURN_NOT_OK(cfi_builder->Finish(&cfi_column));
        ARROW_RETURN_NOT_OK(instrument_event_date_builder->Finish(&instrument_event_date_column));
        ARROW_RETURN_NOT_OK(strike_price_builder->Finish(&strike_price_column));
        ARROW_RETURN_NOT_OK(dark_eligibility_builder->Finish(&dark_eligibility_column));
        ARROW_RETURN_NOT_OK(dark_lis_threshold_builder->Finish(&dark_lis_threshold_column));
        ARROW_RETURN_NOT_OK(dark_min_quantity_builder->Finish(&dark_min_quantity_column));
        ARROW_RETURN_NOT_OK(date_of_last_trade_builder->Finish(&date_of_last_trade_column));
        ARROW_RETURN_NOT_OK(depositary_list_builder->Finish(&depositary_list_column));
        ARROW_RETURN_NOT_OK(main_depositary_builder->Finish(&main_depositary_column));
        ARROW_RETURN_NOT_OK(first_settlement_date_builder->Finish(&first_settlement_date_column));
        ARROW_RETURN_NOT_OK(guarantee_indicator_builder->Finish(&guarantee_indicator_column));
        ARROW_RETURN_NOT_OK(icb_builder->Finish(&icb_column));
        ARROW_RETURN_NOT_OK(issuing_country_builder->Finish(&issuing_country_column));
        ARROW_RETURN_NOT_OK(last_adjusted_closing_price_builder->Finish(&last_adjusted_closing_price_column));
        ARROW_RETURN_NOT_OK(lot_size_optional_builder->Finish(&lot_size_optional_column));
        ARROW_RETURN_NOT_OK(maturity_date_optional_builder->Finish(&maturity_date_optional_column));
        ARROW_RETURN_NOT_OK(maximum_decimals_in_quantity_builder->Finish(&maximum_decimals_in_quantity_column));
        ARROW_RETURN_NOT_OK(mic_builder->Finish(&mic_column));
        ARROW_RETURN_NOT_OK(mic_list_builder->Finish(&mic_list_column));
        ARROW_RETURN_NOT_OK(country_of_exchange_optional_builder->Finish(&country_of_exchange_optional_column));
        ARROW_RETURN_NOT_OK(mnemonic_builder->Finish(&mnemonic_column));
        ARROW_RETURN_NOT_OK(underlying_mic_builder->Finish(&underlying_mic_column));
        ARROW_RETURN_NOT_OK(underlying_isin_code_builder->Finish(&underlying_isin_code_column));
        ARROW_RETURN_NOT_OK(trading_currency_optional_builder->Finish(&trading_currency_optional_column));
        ARROW_RETURN_NOT_OK(trading_currency_indicator_builder->Finish(&trading_currency_indicator_column));
        ARROW_RETURN_NOT_OK(strike_currency_indicator_builder->Finish(&strike_currency_indicator_column));
        ARROW_RETURN_NOT_OK(number_instrument_circulating_builder->Finish(&number_instrument_circulating_column));
        ARROW_RETURN_NOT_OK(par_value_builder->Finish(&par_value_column));
        ARROW_RETURN_NOT_OK(quantity_notation_builder->Finish(&quantity_notation_column));
        ARROW_RETURN_NOT_OK(inst_unit_exp_builder->Finish(&inst_unit_exp_column));
        ARROW_RETURN_NOT_OK(settlement_delay_builder->Finish(&settlement_delay_column));
        ARROW_RETURN_NOT_OK(strike_currency_builder->Finish(&strike_currency_column));
        ARROW_RETURN_NOT_OK(tax_code_builder->Finish(&tax_code_column));
        ARROW_RETURN_NOT_OK(type_of_corporate_event_builder->Finish(&type_of_corporate_event_column));
        ARROW_RETURN_NOT_OK(type_of_market_admission_builder->Finish(&type_of_market_admission_column));
        ARROW_RETURN_NOT_OK(repo_indicator_builder->Finish(&repo_indicator_column));
        ARROW_RETURN_NOT_OK(issue_price_builder->Finish(&issue_price_column));
        ARROW_RETURN_NOT_OK(nominal_currency_builder->Finish(&nominal_currency_column));
        ARROW_RETURN_NOT_OK(issue_price_decimals_builder->Finish(&issue_price_decimals_column));
        ARROW_RETURN_NOT_OK(strike_price_decimals_builder->Finish(&strike_price_decimals_column));
        ARROW_RETURN_NOT_OK(liquid_instrument_indicator_builder->Finish(&liquid_instrument_indicator_column));
        ARROW_RETURN_NOT_OK(icb_code_builder->Finish(&icb_code_column));
        ARROW_RETURN_NOT_OK(threshold_lis_post_trade_60mn_builder->Finish(&threshold_lis_post_trade_60mn_column));
        ARROW_RETURN_NOT_OK(threshold_lis_post_trade_120mn_builder->Finish(&threshold_lis_post_trade_120mn_column));
        ARROW_RETURN_NOT_OK(threshold_lis_post_trade_eod_builder->Finish(&threshold_lis_post_trade_eod_column));
        ARROW_RETURN_NOT_OK(long_mnemonic_builder->Finish(&long_mnemonic_column));
        ARROW_RETURN_NOT_OK(max_order_amount_call_builder->Finish(&max_order_amount_call_column));
        ARROW_RETURN_NOT_OK(max_order_amount_continuous_builder->Finish(&max_order_amount_continuous_column));
        ARROW_RETURN_NOT_OK(max_order_quantity_call_builder->Finish(&max_order_quantity_call_column));
        ARROW_RETURN_NOT_OK(max_order_quantity_continuous_builder->Finish(&max_order_quantity_continuous_column));
        ARROW_RETURN_NOT_OK(pool_factor_builder->Finish(&pool_factor_column));
        ARROW_RETURN_NOT_OK(emm_pattern_rep_group_builder->Finish(&emm_pattern_rep_group_column));
        ARROW_RETURN_NOT_OK(index_level_builder->Finish(&index_level_column));
        ARROW_RETURN_NOT_OK(pctg_of_capitalization_builder->Finish(&pctg_of_capitalization_column));
        ARROW_RETURN_NOT_OK(prct_varfrom_prev_close_builder->Finish(&prct_varfrom_prev_close_column));
        ARROW_RETURN_NOT_OK(num_traded_instruments_builder->Finish(&num_traded_instruments_column));
        ARROW_RETURN_NOT_OK(index_level_type_builder->Finish(&index_level_type_column));
        ARROW_RETURN_NOT_OK(index_price_code_builder->Finish(&index_price_code_column));
        ARROW_RETURN_NOT_OK(new_stats_group_builder->Finish(&new_stats_group_column));
        ARROW_RETURN_NOT_OK(opening_level_builder->Finish(&opening_level_column));
        ARROW_RETURN_NOT_OK(opening_time_builder->Finish(&opening_time_column));
        ARROW_RETURN_NOT_OK(confirmed_reference_level_builder->Finish(&confirmed_reference_level_column));
        ARROW_RETURN_NOT_OK(confirmed_reference_time_builder->Finish(&confirmed_reference_time_column));
        ARROW_RETURN_NOT_OK(closing_reference_level_builder->Finish(&closing_reference_level_column));
        ARROW_RETURN_NOT_OK(closing_reference_time_builder->Finish(&closing_reference_time_column));
        ARROW_RETURN_NOT_OK(high_level_builder->Finish(&high_level_column));
        ARROW_RETURN_NOT_OK(high_time_builder->Finish(&high_time_column));
        ARROW_RETURN_NOT_OK(low_level_builder->Finish(&low_level_column));
        ARROW_RETURN_NOT_OK(low_time_builder->Finish(&low_time_column));
        ARROW_RETURN_NOT_OK(liquidation_level_builder->Finish(&liquidation_level_column));
        ARROW_RETURN_NOT_OK(liquidation_time_builder->Finish(&liquidation_time_column));
        ARROW_RETURN_NOT_OK(derivatives_instrument_trading_code_builder->Finish(&derivatives_instrument_trading_code_column));
        ARROW_RETURN_NOT_OK(exchange_code_builder->Finish(&exchange_code_column));
        ARROW_RETURN_NOT_OK(maturity_date_builder->Finish(&maturity_date_column));
        ARROW_RETURN_NOT_OK(strategy_code_builder->Finish(&strategy_code_column));
        ARROW_RETURN_NOT_OK(contract_symbol_index_builder->Finish(&contract_symbol_index_column));
        ARROW_RETURN_NOT_OK(cfi_optional_builder->Finish(&cfi_optional_column));
        ARROW_RETURN_NOT_OK(strategy_standing_data_group_builder->Finish(&strategy_standing_data_group_column));
        ARROW_RETURN_NOT_OK(contract_event_date_builder->Finish(&contract_event_date_column));
        ARROW_RETURN_NOT_OK(exer_style_builder->Finish(&exer_style_column));
        ARROW_RETURN_NOT_OK(contract_name_builder->Finish(&contract_name_column));
        ARROW_RETURN_NOT_OK(contract_type_builder->Finish(&contract_type_column));
        ARROW_RETURN_NOT_OK(underlying_type_builder->Finish(&underlying_type_column));
        ARROW_RETURN_NOT_OK(price_decimals_optional_builder->Finish(&price_decimals_optional_column));
        ARROW_RETURN_NOT_OK(ratio_decimals_optional_builder->Finish(&ratio_decimals_optional_column));
        ARROW_RETURN_NOT_OK(country_of_exchange_builder->Finish(&country_of_exchange_column));
        ARROW_RETURN_NOT_OK(product_code_builder->Finish(&product_code_column));
        ARROW_RETURN_NOT_OK(underlying_expiry_builder->Finish(&underlying_expiry_column));
        ARROW_RETURN_NOT_OK(settlement_method_builder->Finish(&settlement_method_column));
        ARROW_RETURN_NOT_OK(trading_currency_builder->Finish(&trading_currency_column));
        ARROW_RETURN_NOT_OK(strike_price_decimals_ratio_builder->Finish(&strike_price_decimals_ratio_column));
        ARROW_RETURN_NOT_OK(contract_trading_type_builder->Finish(&contract_trading_type_column));
        ARROW_RETURN_NOT_OK(underlying_subtype_builder->Finish(&underlying_subtype_column));
        ARROW_RETURN_NOT_OK(mother_stock_isin_builder->Finish(&mother_stock_isin_column));
        ARROW_RETURN_NOT_OK(settlement_tick_size_builder->Finish(&settlement_tick_size_column));
        ARROW_RETURN_NOT_OK(edsp_tick_size_builder->Finish(&edsp_tick_size_column));
        ARROW_RETURN_NOT_OK(underlying_symbol_index_builder->Finish(&underlying_symbol_index_column));
        ARROW_RETURN_NOT_OK(trading_policy_builder->Finish(&trading_policy_column));
        ARROW_RETURN_NOT_OK(reference_spread_table_id_builder->Finish(&reference_spread_table_id_column));
        ARROW_RETURN_NOT_OK(derivatives_market_model_builder->Finish(&derivatives_market_model_column));
        ARROW_RETURN_NOT_OK(trading_unit_builder->Finish(&trading_unit_column));
        ARROW_RETURN_NOT_OK(reference_price_origin_in_opening_call_builder->Finish(&reference_price_origin_in_opening_call_column));
        ARROW_RETURN_NOT_OK(reference_price_origin_in_continuous_builder->Finish(&reference_price_origin_in_continuous_column));
        ARROW_RETURN_NOT_OK(reference_price_origin_in_trading_interruption_builder->Finish(&reference_price_origin_in_trading_interruption_column));
        ARROW_RETURN_NOT_OK(collar_expansion_factor_builder->Finish(&collar_expansion_factor_column));
        ARROW_RETURN_NOT_OK(mifidii_liquid_flag_builder->Finish(&mifidii_liquid_flag_column));
        ARROW_RETURN_NOT_OK(pricing_algorithm_builder->Finish(&pricing_algorithm_column));
        ARROW_RETURN_NOT_OK(contract_emm_properties_group_builder->Finish(&contract_emm_properties_group_column));
        ARROW_RETURN_NOT_OK(lot_size_builder->Finish(&lot_size_column));
        ARROW_RETURN_NOT_OK(last_trading_date_builder->Finish(&last_trading_date_column));
        ARROW_RETURN_NOT_OK(days_to_expiry_builder->Finish(&days_to_expiry_column));
        ARROW_RETURN_NOT_OK(derivatives_instrument_trading_code_optional_builder->Finish(&derivatives_instrument_trading_code_optional_column));
        ARROW_RETURN_NOT_OK(derivatives_instrument_type_builder->Finish(&derivatives_instrument_type_column));
        ARROW_RETURN_NOT_OK(expiry_cycle_type_builder->Finish(&expiry_cycle_type_column));
        ARROW_RETURN_NOT_OK(underlying_derivatives_instrument_trading_code_builder->Finish(&underlying_derivatives_instrument_trading_code_column));
        ARROW_RETURN_NOT_OK(outright_rep_group_builder->Finish(&outright_rep_group_column));
        ARROW_RETURN_NOT_OK(long_order_updates_group_builder->Finish(&long_order_updates_group_column));
        ARROW_RETURN_NOT_OK(package_components_group_builder->Finish(&package_components_group_column));
        ARROW_RETURN_NOT_OK(mifid_instrument_id_type_builder->Finish(&mifid_instrument_id_type_column));
        ARROW_RETURN_NOT_OK(mifid_instrument_id_builder->Finish(&mifid_instrument_id_column));
        ARROW_RETURN_NOT_OK(currency_builder->Finish(&currency_column));
        ARROW_RETURN_NOT_OK(lei_code_builder->Finish(&lei_code_column));
        ARROW_RETURN_NOT_OK(quote_update_type_builder->Finish(&quote_update_type_column));
        ARROW_RETURN_NOT_OK(mifid_price_builder->Finish(&mifid_price_column));
        ARROW_RETURN_NOT_OK(apa_origin_builder->Finish(&apa_origin_column));
        ARROW_RETURN_NOT_OK(second_notional_currency_builder->Finish(&second_notional_currency_column));
        ARROW_RETURN_NOT_OK(underlying_index_name_builder->Finish(&underlying_index_name_column));
        ARROW_RETURN_NOT_OK(underlying_index_term_builder->Finish(&underlying_index_term_column));
        ARROW_RETURN_NOT_OK(option_type_builder->Finish(&option_type_column));
        ARROW_RETURN_NOT_OK(expiry_date_builder->Finish(&expiry_date_column));
        ARROW_RETURN_NOT_OK(mifid_transaction_id_builder->Finish(&mifid_transaction_id_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_market_mechanism_builder->Finish(&efficient_mmt_market_mechanism_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_trading_mode_builder->Finish(&efficient_mmt_trading_mode_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_transaction_category_builder->Finish(&efficient_mmt_transaction_category_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_negotiation_indicator_builder->Finish(&efficient_mmt_negotiation_indicator_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_agency_cross_trade_indicator_builder->Finish(&efficient_mmt_agency_cross_trade_indicator_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_modification_indicator_builder->Finish(&efficient_mmt_modification_indicator_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_benchmark_indicator_builder->Finish(&efficient_mmt_benchmark_indicator_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_special_dividend_indicator_builder->Finish(&efficient_mmt_special_dividend_indicator_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_off_book_automated_indicator_builder->Finish(&efficient_mmt_off_book_automated_indicator_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_contributionto_price_builder->Finish(&efficient_mmt_contributionto_price_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_algorithmic_indicator_builder->Finish(&efficient_mmt_algorithmic_indicator_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_publication_mode_builder->Finish(&efficient_mmt_publication_mode_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_post_trade_deferral_builder->Finish(&efficient_mmt_post_trade_deferral_column));
        ARROW_RETURN_NOT_OK(efficient_mmt_duplicative_indicator_builder->Finish(&efficient_mmt_duplicative_indicator_column));
        ARROW_RETURN_NOT_OK(long_trade_reference_builder->Finish(&long_trade_reference_column));
        ARROW_RETURN_NOT_OK(isin_code_optional_builder->Finish(&isin_code_optional_column));
        ARROW_RETURN_NOT_OK(sedol_code_builder->Finish(&sedol_code_column));
        ARROW_RETURN_NOT_OK(long_issuer_name_builder->Finish(&long_issuer_name_column));
        ARROW_RETURN_NOT_OK(long_instrument_name_builder->Finish(&long_instrument_name_column));
        ARROW_RETURN_NOT_OK(currency_optional_builder->Finish(&currency_optional_column));
        ARROW_RETURN_NOT_OK(date_of_initial_listing_builder->Finish(&date_of_initial_listing_column));
        ARROW_RETURN_NOT_OK(share_amount_in_issue_builder->Finish(&share_amount_in_issue_column));
        ARROW_RETURN_NOT_OK(opened_closed_fund_builder->Finish(&opened_closed_fund_column));
        ARROW_RETURN_NOT_OK(last_nav_price_builder->Finish(&last_nav_price_column));
        ARROW_RETURN_NOT_OK(gross_of_cdsc_indicator_builder->Finish(&gross_of_cdsc_indicator_column));
        ARROW_RETURN_NOT_OK(coupon_builder->Finish(&coupon_column));
        ARROW_RETURN_NOT_OK(closing_price_builder->Finish(&closing_price_column));
        ARROW_RETURN_NOT_OK(mic_optional_builder->Finish(&mic_optional_column));
        ARROW_RETURN_NOT_OK(gross_dividend_payable_per_unit_builder->Finish(&gross_dividend_payable_per_unit_column));
        ARROW_RETURN_NOT_OK(dividend_currency_builder->Finish(&dividend_currency_column));
        ARROW_RETURN_NOT_OK(dividend_record_date_builder->Finish(&dividend_record_date_column));
        ARROW_RETURN_NOT_OK(dividend_rate_builder->Finish(&dividend_rate_column));
        ARROW_RETURN_NOT_OK(ex_dividend_date_builder->Finish(&ex_dividend_date_column));
        ARROW_RETURN_NOT_OK(dividend_payment_date_builder->Finish(&dividend_payment_date_column));
        ARROW_RETURN_NOT_OK(tax_description_attaching_to_a_dividend_builder->Finish(&tax_description_attaching_to_a_dividend_column));
        ARROW_RETURN_NOT_OK(next_meeting_builder->Finish(&next_meeting_column));
        ARROW_RETURN_NOT_OK(gross_dividend_in_euros_builder->Finish(&gross_dividend_in_euros_column));
        ARROW_RETURN_NOT_OK(issue_date_builder->Finish(&issue_date_column));
        ARROW_RETURN_NOT_OK(payment_frequency_builder->Finish(&payment_frequency_column));
        ARROW_RETURN_NOT_OK(minimum_amount_builder->Finish(&minimum_amount_column));
        ARROW_RETURN_NOT_OK(instrument_category_builder->Finish(&instrument_category_column));
        ARROW_RETURN_NOT_OK(security_condition_builder->Finish(&security_condition_column));
        ARROW_RETURN_NOT_OK(price_index_level_decimals_builder->Finish(&price_index_level_decimals_column));
        ARROW_RETURN_NOT_OK(ratio_multiplier_decimals_builder->Finish(&ratio_multiplier_decimals_column));
        ARROW_RETURN_NOT_OK(interest_payment_date_rep_group_builder->Finish(&interest_payment_date_rep_group_column));
        ARROW_RETURN_NOT_OK(bid_offer_date_time_builder->Finish(&bid_offer_date_time_column));
        ARROW_RETURN_NOT_OK(mmt_modification_indicator_builder->Finish(&mmt_modification_indicator_column));
        ARROW_RETURN_NOT_OK(price_builder->Finish(&price_column));
        ARROW_RETURN_NOT_OK(bid_price_builder->Finish(&bid_price_column));
        ARROW_RETURN_NOT_OK(offer_price_builder->Finish(&offer_price_column));
        ARROW_RETURN_NOT_OK(quantity_builder->Finish(&quantity_column));
        ARROW_RETURN_NOT_OK(notional_amount_traded_builder->Finish(&notional_amount_traded_column));
        ARROW_RETURN_NOT_OK(nav_price_builder->Finish(&nav_price_column));
        ARROW_RETURN_NOT_OK(event_time_optional_builder->Finish(&event_time_optional_column));
        ARROW_RETURN_NOT_OK(nav_bid_price_builder->Finish(&nav_bid_price_column));
        ARROW_RETURN_NOT_OK(nav_offer_price_builder->Finish(&nav_offer_price_column));
        ARROW_RETURN_NOT_OK(last_md_seq_num_builder->Finish(&last_md_seq_num_column));
        ARROW_RETURN_NOT_OK(snapshot_time_builder->Finish(&snapshot_time_column));

        auto batch = arrow::RecordBatch::Make(schema, row_count, {
            event_type_column,
            md_seq_num_column,
            session_trading_day_column,
            event_time_column,
            md_seq_num_optional_column,
            technical_notification_type_column,
            rebroadcast_indicator_column,
            retransmission_start_time_column,
            retransmission_end_time_column,
            symbol_index_optional_column,
            emm_column,
            block_length_short_column,
            num_in_group_column,
            market_updates_group_column,
            order_updates_group_column,
            price_updates_group_column,
            trading_date_time_column,
            publication_date_time_column,
            trade_type_column,
            mifid_instrument_id_type_optional_column,
            mifid_instrument_id_optional_column,
            mifid_execution_id_column,
            mifid_price_optional_column,
            mifid_quantity_column,
            mifid_price_notation_column,
            mifid_currency_column,
            mifid_qty_in_msrmt_unit_notation_column,
            mifid_quantity_measurement_unit_column,
            mifid_notional_amount_column,
            notional_currency_column,
            mifid_clearing_flag_column,
            mmt_market_mechanism_column,
            mmt_trading_mode_column,
            mmt_transaction_category_column,
            mmt_negotiation_indicator_column,
            mmt_agency_cross_trade_indicator_column,
            mmt_modification_indicator_char_4_optional_column,
            mmt_benchmark_indicator_column,
            mmt_special_dividend_indicator_column,
            mmt_off_book_automated_indicator_column,
            mmt_contributionto_price_column,
            mmt_algorithmic_indicator_column,
            mmt_publication_mode_column,
            mmt_post_trade_deferral_column,
            mmt_duplicative_indicator_column,
            transaction_type_column,
            effective_date_indicator_column,
            block_trade_code_column,
            trade_reference_column,
            original_report_timestamp_column,
            transparency_indicator_column,
            currency_coefficient_column,
            price_multiplier_column,
            price_multiplier_decimals_column,
            venue_column,
            start_time_vwap_column,
            end_time_vwap_column,
            mifid_emission_allowance_type_column,
            market_of_reference_mic_column,
            evaluated_price_column,
            message_price_notation_column,
            settlement_date_column,
            repo_settlement_date_column,
            trade_unique_identifier_column,
            not_used_group_column,
            market_states_group_column,
            emm_optional_column,
            pattern_id_column,
            timetables_group_column,
            symbol_index_column,
            optiq_segment_column,
            partition_id_column,
            full_instrument_name_column,
            instrument_name_column,
            instrument_trading_code_column,
            instrument_group_code_column,
            isin_code_column,
            price_decimals_column,
            quantity_decimals_column,
            amount_decimals_column,
            ratio_decimals_column,
            cfi_column,
            instrument_event_date_column,
            strike_price_column,
            dark_eligibility_column,
            dark_lis_threshold_column,
            dark_min_quantity_column,
            date_of_last_trade_column,
            depositary_list_column,
            main_depositary_column,
            first_settlement_date_column,
            guarantee_indicator_column,
            icb_column,
            issuing_country_column,
            last_adjusted_closing_price_column,
            lot_size_optional_column,
            maturity_date_optional_column,
            maximum_decimals_in_quantity_column,
            mic_column,
            mic_list_column,
            country_of_exchange_optional_column,
            mnemonic_column,
            underlying_mic_column,
            underlying_isin_code_column,
            trading_currency_optional_column,
            trading_currency_indicator_column,
            strike_currency_indicator_column,
            number_instrument_circulating_column,
            par_value_column,
            quantity_notation_column,
            inst_unit_exp_column,
            settlement_delay_column,
            strike_currency_column,
            tax_code_column,
            type_of_corporate_event_column,
            type_of_market_admission_column,
            repo_indicator_column,
            issue_price_column,
            nominal_currency_column,
            issue_price_decimals_column,
            strike_price_decimals_column,
            liquid_instrument_indicator_column,
            icb_code_column,
            threshold_lis_post_trade_60mn_column,
            threshold_lis_post_trade_120mn_column,
            threshold_lis_post_trade_eod_column,
            long_mnemonic_column,
            max_order_amount_call_column,
            max_order_amount_continuous_column,
            max_order_quantity_call_column,
            max_order_quantity_continuous_column,
            pool_factor_column,
            emm_pattern_rep_group_column,
            index_level_column,
            pctg_of_capitalization_column,
            prct_varfrom_prev_close_column,
            num_traded_instruments_column,
            index_level_type_column,
            index_price_code_column,
            new_stats_group_column,
            opening_level_column,
            opening_time_column,
            confirmed_reference_level_column,
            confirmed_reference_time_column,
            closing_reference_level_column,
            closing_reference_time_column,
            high_level_column,
            high_time_column,
            low_level_column,
            low_time_column,
            liquidation_level_column,
            liquidation_time_column,
            derivatives_instrument_trading_code_column,
            exchange_code_column,
            maturity_date_column,
            strategy_code_column,
            contract_symbol_index_column,
            cfi_optional_column,
            strategy_standing_data_group_column,
            contract_event_date_column,
            exer_style_column,
            contract_name_column,
            contract_type_column,
            underlying_type_column,
            price_decimals_optional_column,
            ratio_decimals_optional_column,
            country_of_exchange_column,
            product_code_column,
            underlying_expiry_column,
            settlement_method_column,
            trading_currency_column,
            strike_price_decimals_ratio_column,
            contract_trading_type_column,
            underlying_subtype_column,
            mother_stock_isin_column,
            settlement_tick_size_column,
            edsp_tick_size_column,
            underlying_symbol_index_column,
            trading_policy_column,
            reference_spread_table_id_column,
            derivatives_market_model_column,
            trading_unit_column,
            reference_price_origin_in_opening_call_column,
            reference_price_origin_in_continuous_column,
            reference_price_origin_in_trading_interruption_column,
            collar_expansion_factor_column,
            mifidii_liquid_flag_column,
            pricing_algorithm_column,
            contract_emm_properties_group_column,
            lot_size_column,
            last_trading_date_column,
            days_to_expiry_column,
            derivatives_instrument_trading_code_optional_column,
            derivatives_instrument_type_column,
            expiry_cycle_type_column,
            underlying_derivatives_instrument_trading_code_column,
            outright_rep_group_column,
            long_order_updates_group_column,
            package_components_group_column,
            mifid_instrument_id_type_column,
            mifid_instrument_id_column,
            currency_column,
            lei_code_column,
            quote_update_type_column,
            mifid_price_column,
            apa_origin_column,
            second_notional_currency_column,
            underlying_index_name_column,
            underlying_index_term_column,
            option_type_column,
            expiry_date_column,
            mifid_transaction_id_column,
            efficient_mmt_market_mechanism_column,
            efficient_mmt_trading_mode_column,
            efficient_mmt_transaction_category_column,
            efficient_mmt_negotiation_indicator_column,
            efficient_mmt_agency_cross_trade_indicator_column,
            efficient_mmt_modification_indicator_column,
            efficient_mmt_benchmark_indicator_column,
            efficient_mmt_special_dividend_indicator_column,
            efficient_mmt_off_book_automated_indicator_column,
            efficient_mmt_contributionto_price_column,
            efficient_mmt_algorithmic_indicator_column,
            efficient_mmt_publication_mode_column,
            efficient_mmt_post_trade_deferral_column,
            efficient_mmt_duplicative_indicator_column,
            long_trade_reference_column,
            isin_code_optional_column,
            sedol_code_column,
            long_issuer_name_column,
            long_instrument_name_column,
            currency_optional_column,
            date_of_initial_listing_column,
            share_amount_in_issue_column,
            opened_closed_fund_column,
            last_nav_price_column,
            gross_of_cdsc_indicator_column,
            coupon_column,
            closing_price_column,
            mic_optional_column,
            gross_dividend_payable_per_unit_column,
            dividend_currency_column,
            dividend_record_date_column,
            dividend_rate_column,
            ex_dividend_date_column,
            dividend_payment_date_column,
            tax_description_attaching_to_a_dividend_column,
            next_meeting_column,
            gross_dividend_in_euros_column,
            issue_date_column,
            payment_frequency_column,
            minimum_amount_column,
            instrument_category_column,
            security_condition_column,
            price_index_level_decimals_column,
            ratio_multiplier_decimals_column,
            interest_payment_date_rep_group_column,
            bid_offer_date_time_column,
            mmt_modification_indicator_column,
            price_column,
            bid_price_column,
            offer_price_column,
            quantity_column,
            notional_amount_traded_column,
            nav_price_column,
            event_time_optional_column,
            nav_bid_price_column,
            nav_offer_price_column,
            last_md_seq_num_column,
            snapshot_time_column,
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
        md_seq_num_builder = std::make_unique<arrow::UInt64Builder>();
        session_trading_day_builder = std::make_unique<arrow::UInt16Builder>();
        event_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        md_seq_num_optional_builder = std::make_unique<arrow::UInt64Builder>();
        technical_notification_type_builder = std::make_unique<arrow::UInt8Builder>();
        rebroadcast_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        retransmission_start_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        retransmission_end_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        symbol_index_optional_builder = std::make_unique<arrow::UInt32Builder>();
        emm_builder = std::make_unique<arrow::UInt8Builder>();
        block_length_short_builder = std::make_unique<arrow::UInt8Builder>();
        num_in_group_builder = std::make_unique<arrow::UInt8Builder>();
        market_updates_group_builder = std::make_unique<arrow::StringBuilder>();
        order_updates_group_builder = std::make_unique<arrow::StringBuilder>();
        price_updates_group_builder = std::make_unique<arrow::StringBuilder>();
        trading_date_time_builder = std::make_unique<arrow::StringBuilder>();
        publication_date_time_builder = std::make_unique<arrow::StringBuilder>();
        trade_type_builder = std::make_unique<arrow::UInt8Builder>();
        mifid_instrument_id_type_optional_builder = std::make_unique<arrow::StringBuilder>();
        mifid_instrument_id_optional_builder = std::make_unique<arrow::StringBuilder>();
        mifid_execution_id_builder = std::make_unique<arrow::StringBuilder>();
        mifid_price_optional_builder = std::make_unique<arrow::StringBuilder>();
        mifid_quantity_builder = std::make_unique<arrow::StringBuilder>();
        mifid_price_notation_builder = std::make_unique<arrow::StringBuilder>();
        mifid_currency_builder = std::make_unique<arrow::StringBuilder>();
        mifid_qty_in_msrmt_unit_notation_builder = std::make_unique<arrow::StringBuilder>();
        mifid_quantity_measurement_unit_builder = std::make_unique<arrow::StringBuilder>();
        mifid_notional_amount_builder = std::make_unique<arrow::StringBuilder>();
        notional_currency_builder = std::make_unique<arrow::StringBuilder>();
        mifid_clearing_flag_builder = std::make_unique<arrow::StringBuilder>();
        mmt_market_mechanism_builder = std::make_unique<arrow::UInt8Builder>();
        mmt_trading_mode_builder = std::make_unique<arrow::StringBuilder>();
        mmt_transaction_category_builder = std::make_unique<arrow::StringBuilder>();
        mmt_negotiation_indicator_builder = std::make_unique<arrow::StringBuilder>();
        mmt_agency_cross_trade_indicator_builder = std::make_unique<arrow::StringBuilder>();
        mmt_modification_indicator_char_4_optional_builder = std::make_unique<arrow::StringBuilder>();
        mmt_benchmark_indicator_builder = std::make_unique<arrow::StringBuilder>();
        mmt_special_dividend_indicator_builder = std::make_unique<arrow::StringBuilder>();
        mmt_off_book_automated_indicator_builder = std::make_unique<arrow::StringBuilder>();
        mmt_contributionto_price_builder = std::make_unique<arrow::StringBuilder>();
        mmt_algorithmic_indicator_builder = std::make_unique<arrow::StringBuilder>();
        mmt_publication_mode_builder = std::make_unique<arrow::StringBuilder>();
        mmt_post_trade_deferral_builder = std::make_unique<arrow::StringBuilder>();
        mmt_duplicative_indicator_builder = std::make_unique<arrow::StringBuilder>();
        transaction_type_builder = std::make_unique<arrow::UInt8Builder>();
        effective_date_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        block_trade_code_builder = std::make_unique<arrow::StringBuilder>();
        trade_reference_builder = std::make_unique<arrow::StringBuilder>();
        original_report_timestamp_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        transparency_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        currency_coefficient_builder = std::make_unique<arrow::UInt32Builder>();
        price_multiplier_builder = std::make_unique<arrow::UInt32Builder>();
        price_multiplier_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        venue_builder = std::make_unique<arrow::StringBuilder>();
        start_time_vwap_builder = std::make_unique<arrow::UInt32Builder>();
        end_time_vwap_builder = std::make_unique<arrow::UInt32Builder>();
        mifid_emission_allowance_type_builder = std::make_unique<arrow::StringBuilder>();
        market_of_reference_mic_builder = std::make_unique<arrow::StringBuilder>();
        evaluated_price_builder = std::make_unique<arrow::Int64Builder>();
        message_price_notation_builder = std::make_unique<arrow::UInt8Builder>();
        settlement_date_builder = std::make_unique<arrow::UInt16Builder>();
        repo_settlement_date_builder = std::make_unique<arrow::UInt16Builder>();
        trade_unique_identifier_builder = std::make_unique<arrow::StringBuilder>();
        not_used_group_builder = std::make_unique<arrow::StringBuilder>();
        market_states_group_builder = std::make_unique<arrow::StringBuilder>();
        emm_optional_builder = std::make_unique<arrow::UInt8Builder>();
        pattern_id_builder = std::make_unique<arrow::UInt16Builder>();
        timetables_group_builder = std::make_unique<arrow::StringBuilder>();
        symbol_index_builder = std::make_unique<arrow::UInt32Builder>();
        optiq_segment_builder = std::make_unique<arrow::UInt8Builder>();
        partition_id_builder = std::make_unique<arrow::UInt16Builder>();
        full_instrument_name_builder = std::make_unique<arrow::StringBuilder>();
        instrument_name_builder = std::make_unique<arrow::StringBuilder>();
        instrument_trading_code_builder = std::make_unique<arrow::StringBuilder>();
        instrument_group_code_builder = std::make_unique<arrow::StringBuilder>();
        isin_code_builder = std::make_unique<arrow::StringBuilder>();
        price_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        quantity_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        amount_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        ratio_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        cfi_builder = std::make_unique<arrow::StringBuilder>();
        instrument_event_date_builder = std::make_unique<arrow::UInt16Builder>();
        strike_price_builder = std::make_unique<arrow::Int64Builder>();
        dark_eligibility_builder = std::make_unique<arrow::UInt8Builder>();
        dark_lis_threshold_builder = std::make_unique<arrow::UInt64Builder>();
        dark_min_quantity_builder = std::make_unique<arrow::UInt32Builder>();
        date_of_last_trade_builder = std::make_unique<arrow::UInt16Builder>();
        depositary_list_builder = std::make_unique<arrow::StringBuilder>();
        main_depositary_builder = std::make_unique<arrow::StringBuilder>();
        first_settlement_date_builder = std::make_unique<arrow::UInt16Builder>();
        guarantee_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        icb_builder = std::make_unique<arrow::StringBuilder>();
        issuing_country_builder = std::make_unique<arrow::StringBuilder>();
        last_adjusted_closing_price_builder = std::make_unique<arrow::Int64Builder>();
        lot_size_optional_builder = std::make_unique<arrow::UInt64Builder>();
        maturity_date_optional_builder = std::make_unique<arrow::StringBuilder>();
        maximum_decimals_in_quantity_builder = std::make_unique<arrow::UInt8Builder>();
        mic_builder = std::make_unique<arrow::StringBuilder>();
        mic_list_builder = std::make_unique<arrow::StringBuilder>();
        country_of_exchange_optional_builder = std::make_unique<arrow::StringBuilder>();
        mnemonic_builder = std::make_unique<arrow::StringBuilder>();
        underlying_mic_builder = std::make_unique<arrow::StringBuilder>();
        underlying_isin_code_builder = std::make_unique<arrow::StringBuilder>();
        trading_currency_optional_builder = std::make_unique<arrow::StringBuilder>();
        trading_currency_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        strike_currency_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        number_instrument_circulating_builder = std::make_unique<arrow::UInt64Builder>();
        par_value_builder = std::make_unique<arrow::UInt64Builder>();
        quantity_notation_builder = std::make_unique<arrow::StringBuilder>();
        inst_unit_exp_builder = std::make_unique<arrow::UInt8Builder>();
        settlement_delay_builder = std::make_unique<arrow::StringBuilder>();
        strike_currency_builder = std::make_unique<arrow::StringBuilder>();
        tax_code_builder = std::make_unique<arrow::UInt8Builder>();
        type_of_corporate_event_builder = std::make_unique<arrow::StringBuilder>();
        type_of_market_admission_builder = std::make_unique<arrow::StringBuilder>();
        repo_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        issue_price_builder = std::make_unique<arrow::Int64Builder>();
        nominal_currency_builder = std::make_unique<arrow::StringBuilder>();
        issue_price_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        strike_price_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        liquid_instrument_indicator_builder = std::make_unique<arrow::UInt8Builder>();
        icb_code_builder = std::make_unique<arrow::StringBuilder>();
        threshold_lis_post_trade_60mn_builder = std::make_unique<arrow::UInt64Builder>();
        threshold_lis_post_trade_120mn_builder = std::make_unique<arrow::UInt64Builder>();
        threshold_lis_post_trade_eod_builder = std::make_unique<arrow::UInt64Builder>();
        long_mnemonic_builder = std::make_unique<arrow::StringBuilder>();
        max_order_amount_call_builder = std::make_unique<arrow::UInt64Builder>();
        max_order_amount_continuous_builder = std::make_unique<arrow::UInt64Builder>();
        max_order_quantity_call_builder = std::make_unique<arrow::UInt64Builder>();
        max_order_quantity_continuous_builder = std::make_unique<arrow::UInt64Builder>();
        pool_factor_builder = std::make_unique<arrow::UInt32Builder>();
        emm_pattern_rep_group_builder = std::make_unique<arrow::StringBuilder>();
        index_level_builder = std::make_unique<arrow::Int64Builder>();
        pctg_of_capitalization_builder = std::make_unique<arrow::UInt64Builder>();
        prct_varfrom_prev_close_builder = std::make_unique<arrow::Int64Builder>();
        num_traded_instruments_builder = std::make_unique<arrow::UInt16Builder>();
        index_level_type_builder = std::make_unique<arrow::UInt8Builder>();
        index_price_code_builder = std::make_unique<arrow::UInt8Builder>();
        new_stats_group_builder = std::make_unique<arrow::StringBuilder>();
        opening_level_builder = std::make_unique<arrow::Int64Builder>();
        opening_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        confirmed_reference_level_builder = std::make_unique<arrow::Int64Builder>();
        confirmed_reference_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        closing_reference_level_builder = std::make_unique<arrow::Int64Builder>();
        closing_reference_time_builder = std::make_unique<arrow::UInt64Builder>();
        high_level_builder = std::make_unique<arrow::Int64Builder>();
        high_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        low_level_builder = std::make_unique<arrow::Int64Builder>();
        low_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        liquidation_level_builder = std::make_unique<arrow::Int64Builder>();
        liquidation_time_builder = std::make_unique<arrow::UInt64Builder>();
        derivatives_instrument_trading_code_builder = std::make_unique<arrow::StringBuilder>();
        exchange_code_builder = std::make_unique<arrow::StringBuilder>();
        maturity_date_builder = std::make_unique<arrow::StringBuilder>();
        strategy_code_builder = std::make_unique<arrow::StringBuilder>();
        contract_symbol_index_builder = std::make_unique<arrow::UInt32Builder>();
        cfi_optional_builder = std::make_unique<arrow::StringBuilder>();
        strategy_standing_data_group_builder = std::make_unique<arrow::StringBuilder>();
        contract_event_date_builder = std::make_unique<arrow::UInt16Builder>();
        exer_style_builder = std::make_unique<arrow::UInt8Builder>();
        contract_name_builder = std::make_unique<arrow::StringBuilder>();
        contract_type_builder = std::make_unique<arrow::StringBuilder>();
        underlying_type_builder = std::make_unique<arrow::StringBuilder>();
        price_decimals_optional_builder = std::make_unique<arrow::UInt8Builder>();
        ratio_decimals_optional_builder = std::make_unique<arrow::UInt8Builder>();
        country_of_exchange_builder = std::make_unique<arrow::StringBuilder>();
        product_code_builder = std::make_unique<arrow::StringBuilder>();
        underlying_expiry_builder = std::make_unique<arrow::UInt32Builder>();
        settlement_method_builder = std::make_unique<arrow::StringBuilder>();
        trading_currency_builder = std::make_unique<arrow::StringBuilder>();
        strike_price_decimals_ratio_builder = std::make_unique<arrow::UInt8Builder>();
        contract_trading_type_builder = std::make_unique<arrow::UInt8Builder>();
        underlying_subtype_builder = std::make_unique<arrow::UInt8Builder>();
        mother_stock_isin_builder = std::make_unique<arrow::StringBuilder>();
        settlement_tick_size_builder = std::make_unique<arrow::UInt64Builder>();
        edsp_tick_size_builder = std::make_unique<arrow::UInt64Builder>();
        underlying_symbol_index_builder = std::make_unique<arrow::UInt32Builder>();
        trading_policy_builder = std::make_unique<arrow::UInt8Builder>();
        reference_spread_table_id_builder = std::make_unique<arrow::UInt16Builder>();
        derivatives_market_model_builder = std::make_unique<arrow::UInt8Builder>();
        trading_unit_builder = std::make_unique<arrow::UInt64Builder>();
        reference_price_origin_in_opening_call_builder = std::make_unique<arrow::UInt8Builder>();
        reference_price_origin_in_continuous_builder = std::make_unique<arrow::UInt8Builder>();
        reference_price_origin_in_trading_interruption_builder = std::make_unique<arrow::UInt8Builder>();
        collar_expansion_factor_builder = std::make_unique<arrow::UInt8Builder>();
        mifidii_liquid_flag_builder = std::make_unique<arrow::UInt8Builder>();
        pricing_algorithm_builder = std::make_unique<arrow::UInt8Builder>();
        contract_emm_properties_group_builder = std::make_unique<arrow::StringBuilder>();
        lot_size_builder = std::make_unique<arrow::UInt64Builder>();
        last_trading_date_builder = std::make_unique<arrow::UInt16Builder>();
        days_to_expiry_builder = std::make_unique<arrow::UInt16Builder>();
        derivatives_instrument_trading_code_optional_builder = std::make_unique<arrow::StringBuilder>();
        derivatives_instrument_type_builder = std::make_unique<arrow::UInt8Builder>();
        expiry_cycle_type_builder = std::make_unique<arrow::UInt8Builder>();
        underlying_derivatives_instrument_trading_code_builder = std::make_unique<arrow::StringBuilder>();
        outright_rep_group_builder = std::make_unique<arrow::StringBuilder>();
        long_order_updates_group_builder = std::make_unique<arrow::StringBuilder>();
        package_components_group_builder = std::make_unique<arrow::StringBuilder>();
        mifid_instrument_id_type_builder = std::make_unique<arrow::StringBuilder>();
        mifid_instrument_id_builder = std::make_unique<arrow::StringBuilder>();
        currency_builder = std::make_unique<arrow::StringBuilder>();
        lei_code_builder = std::make_unique<arrow::StringBuilder>();
        quote_update_type_builder = std::make_unique<arrow::UInt8Builder>();
        mifid_price_builder = std::make_unique<arrow::StringBuilder>();
        apa_origin_builder = std::make_unique<arrow::StringBuilder>();
        second_notional_currency_builder = std::make_unique<arrow::StringBuilder>();
        underlying_index_name_builder = std::make_unique<arrow::StringBuilder>();
        underlying_index_term_builder = std::make_unique<arrow::StringBuilder>();
        option_type_builder = std::make_unique<arrow::UInt8Builder>();
        expiry_date_builder = std::make_unique<arrow::StringBuilder>();
        mifid_transaction_id_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_market_mechanism_builder = std::make_unique<arrow::UInt8Builder>();
        efficient_mmt_trading_mode_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_transaction_category_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_negotiation_indicator_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_agency_cross_trade_indicator_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_modification_indicator_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_benchmark_indicator_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_special_dividend_indicator_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_off_book_automated_indicator_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_contributionto_price_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_algorithmic_indicator_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_publication_mode_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_post_trade_deferral_builder = std::make_unique<arrow::StringBuilder>();
        efficient_mmt_duplicative_indicator_builder = std::make_unique<arrow::StringBuilder>();
        long_trade_reference_builder = std::make_unique<arrow::StringBuilder>();
        isin_code_optional_builder = std::make_unique<arrow::StringBuilder>();
        sedol_code_builder = std::make_unique<arrow::StringBuilder>();
        long_issuer_name_builder = std::make_unique<arrow::StringBuilder>();
        long_instrument_name_builder = std::make_unique<arrow::StringBuilder>();
        currency_optional_builder = std::make_unique<arrow::StringBuilder>();
        date_of_initial_listing_builder = std::make_unique<arrow::UInt16Builder>();
        share_amount_in_issue_builder = std::make_unique<arrow::Int64Builder>();
        opened_closed_fund_builder = std::make_unique<arrow::StringBuilder>();
        last_nav_price_builder = std::make_unique<arrow::Int64Builder>();
        gross_of_cdsc_indicator_builder = std::make_unique<arrow::StringBuilder>();
        coupon_builder = std::make_unique<arrow::Int64Builder>();
        closing_price_builder = std::make_unique<arrow::Int64Builder>();
        mic_optional_builder = std::make_unique<arrow::StringBuilder>();
        gross_dividend_payable_per_unit_builder = std::make_unique<arrow::Int64Builder>();
        dividend_currency_builder = std::make_unique<arrow::StringBuilder>();
        dividend_record_date_builder = std::make_unique<arrow::UInt16Builder>();
        dividend_rate_builder = std::make_unique<arrow::UInt64Builder>();
        ex_dividend_date_builder = std::make_unique<arrow::UInt16Builder>();
        dividend_payment_date_builder = std::make_unique<arrow::UInt16Builder>();
        tax_description_attaching_to_a_dividend_builder = std::make_unique<arrow::StringBuilder>();
        next_meeting_builder = std::make_unique<arrow::StringBuilder>();
        gross_dividend_in_euros_builder = std::make_unique<arrow::Int64Builder>();
        issue_date_builder = std::make_unique<arrow::UInt16Builder>();
        payment_frequency_builder = std::make_unique<arrow::UInt8Builder>();
        minimum_amount_builder = std::make_unique<arrow::Int64Builder>();
        instrument_category_builder = std::make_unique<arrow::UInt8Builder>();
        security_condition_builder = std::make_unique<arrow::StringBuilder>();
        price_index_level_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        ratio_multiplier_decimals_builder = std::make_unique<arrow::UInt8Builder>();
        interest_payment_date_rep_group_builder = std::make_unique<arrow::StringBuilder>();
        bid_offer_date_time_builder = std::make_unique<arrow::UInt64Builder>();
        mmt_modification_indicator_builder = std::make_unique<arrow::StringBuilder>();
        price_builder = std::make_unique<arrow::Int64Builder>();
        bid_price_builder = std::make_unique<arrow::Int64Builder>();
        offer_price_builder = std::make_unique<arrow::Int64Builder>();
        quantity_builder = std::make_unique<arrow::UInt64Builder>();
        notional_amount_traded_builder = std::make_unique<arrow::Int64Builder>();
        nav_price_builder = std::make_unique<arrow::Int64Builder>();
        event_time_optional_builder = std::make_unique<arrow::UInt64Builder>();
        nav_bid_price_builder = std::make_unique<arrow::Int64Builder>();
        nav_offer_price_builder = std::make_unique<arrow::Int64Builder>();
        last_md_seq_num_builder = std::make_unique<arrow::UInt64Builder>();
        snapshot_time_builder = std::make_unique<arrow::UInt64Builder>();

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
        std::unique_ptr<arrow::UInt64Builder> md_seq_num_builder;
        std::unique_ptr<arrow::UInt16Builder> session_trading_day_builder;
        std::unique_ptr<arrow::Time64Builder> event_time_builder;
        std::unique_ptr<arrow::UInt64Builder> md_seq_num_optional_builder;
        std::unique_ptr<arrow::UInt8Builder> technical_notification_type_builder;
        std::unique_ptr<arrow::UInt8Builder> rebroadcast_indicator_builder;
        std::unique_ptr<arrow::Time64Builder> retransmission_start_time_builder;
        std::unique_ptr<arrow::Time64Builder> retransmission_end_time_builder;
        std::unique_ptr<arrow::UInt32Builder> symbol_index_optional_builder;
        std::unique_ptr<arrow::UInt8Builder> emm_builder;
        std::unique_ptr<arrow::UInt8Builder> block_length_short_builder;
        std::unique_ptr<arrow::UInt8Builder> num_in_group_builder;
        std::unique_ptr<arrow::StringBuilder> market_updates_group_builder;
        std::unique_ptr<arrow::StringBuilder> order_updates_group_builder;
        std::unique_ptr<arrow::StringBuilder> price_updates_group_builder;
        std::unique_ptr<arrow::StringBuilder> trading_date_time_builder;
        std::unique_ptr<arrow::StringBuilder> publication_date_time_builder;
        std::unique_ptr<arrow::UInt8Builder> trade_type_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_instrument_id_type_optional_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_instrument_id_optional_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_execution_id_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_price_optional_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_quantity_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_price_notation_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_currency_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_qty_in_msrmt_unit_notation_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_quantity_measurement_unit_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_notional_amount_builder;
        std::unique_ptr<arrow::StringBuilder> notional_currency_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_clearing_flag_builder;
        std::unique_ptr<arrow::UInt8Builder> mmt_market_mechanism_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_trading_mode_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_transaction_category_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_negotiation_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_agency_cross_trade_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_modification_indicator_char_4_optional_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_benchmark_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_special_dividend_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_off_book_automated_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_contributionto_price_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_algorithmic_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_publication_mode_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_post_trade_deferral_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_duplicative_indicator_builder;
        std::unique_ptr<arrow::UInt8Builder> transaction_type_builder;
        std::unique_ptr<arrow::UInt8Builder> effective_date_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> block_trade_code_builder;
        std::unique_ptr<arrow::StringBuilder> trade_reference_builder;
        std::unique_ptr<arrow::Time64Builder> original_report_timestamp_builder;
        std::unique_ptr<arrow::UInt8Builder> transparency_indicator_builder;
        std::unique_ptr<arrow::UInt32Builder> currency_coefficient_builder;
        std::unique_ptr<arrow::UInt32Builder> price_multiplier_builder;
        std::unique_ptr<arrow::UInt8Builder> price_multiplier_decimals_builder;
        std::unique_ptr<arrow::StringBuilder> venue_builder;
        std::unique_ptr<arrow::UInt32Builder> start_time_vwap_builder;
        std::unique_ptr<arrow::UInt32Builder> end_time_vwap_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_emission_allowance_type_builder;
        std::unique_ptr<arrow::StringBuilder> market_of_reference_mic_builder;
        std::unique_ptr<arrow::Int64Builder> evaluated_price_builder;
        std::unique_ptr<arrow::UInt8Builder> message_price_notation_builder;
        std::unique_ptr<arrow::UInt16Builder> settlement_date_builder;
        std::unique_ptr<arrow::UInt16Builder> repo_settlement_date_builder;
        std::unique_ptr<arrow::StringBuilder> trade_unique_identifier_builder;
        std::unique_ptr<arrow::StringBuilder> not_used_group_builder;
        std::unique_ptr<arrow::StringBuilder> market_states_group_builder;
        std::unique_ptr<arrow::UInt8Builder> emm_optional_builder;
        std::unique_ptr<arrow::UInt16Builder> pattern_id_builder;
        std::unique_ptr<arrow::StringBuilder> timetables_group_builder;
        std::unique_ptr<arrow::UInt32Builder> symbol_index_builder;
        std::unique_ptr<arrow::UInt8Builder> optiq_segment_builder;
        std::unique_ptr<arrow::UInt16Builder> partition_id_builder;
        std::unique_ptr<arrow::StringBuilder> full_instrument_name_builder;
        std::unique_ptr<arrow::StringBuilder> instrument_name_builder;
        std::unique_ptr<arrow::StringBuilder> instrument_trading_code_builder;
        std::unique_ptr<arrow::StringBuilder> instrument_group_code_builder;
        std::unique_ptr<arrow::StringBuilder> isin_code_builder;
        std::unique_ptr<arrow::UInt8Builder> price_decimals_builder;
        std::unique_ptr<arrow::UInt8Builder> quantity_decimals_builder;
        std::unique_ptr<arrow::UInt8Builder> amount_decimals_builder;
        std::unique_ptr<arrow::UInt8Builder> ratio_decimals_builder;
        std::unique_ptr<arrow::StringBuilder> cfi_builder;
        std::unique_ptr<arrow::UInt16Builder> instrument_event_date_builder;
        std::unique_ptr<arrow::Int64Builder> strike_price_builder;
        std::unique_ptr<arrow::UInt8Builder> dark_eligibility_builder;
        std::unique_ptr<arrow::UInt64Builder> dark_lis_threshold_builder;
        std::unique_ptr<arrow::UInt32Builder> dark_min_quantity_builder;
        std::unique_ptr<arrow::UInt16Builder> date_of_last_trade_builder;
        std::unique_ptr<arrow::StringBuilder> depositary_list_builder;
        std::unique_ptr<arrow::StringBuilder> main_depositary_builder;
        std::unique_ptr<arrow::UInt16Builder> first_settlement_date_builder;
        std::unique_ptr<arrow::UInt8Builder> guarantee_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> icb_builder;
        std::unique_ptr<arrow::StringBuilder> issuing_country_builder;
        std::unique_ptr<arrow::Int64Builder> last_adjusted_closing_price_builder;
        std::unique_ptr<arrow::UInt64Builder> lot_size_optional_builder;
        std::unique_ptr<arrow::StringBuilder> maturity_date_optional_builder;
        std::unique_ptr<arrow::UInt8Builder> maximum_decimals_in_quantity_builder;
        std::unique_ptr<arrow::StringBuilder> mic_builder;
        std::unique_ptr<arrow::StringBuilder> mic_list_builder;
        std::unique_ptr<arrow::StringBuilder> country_of_exchange_optional_builder;
        std::unique_ptr<arrow::StringBuilder> mnemonic_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_mic_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_isin_code_builder;
        std::unique_ptr<arrow::StringBuilder> trading_currency_optional_builder;
        std::unique_ptr<arrow::UInt8Builder> trading_currency_indicator_builder;
        std::unique_ptr<arrow::UInt8Builder> strike_currency_indicator_builder;
        std::unique_ptr<arrow::UInt64Builder> number_instrument_circulating_builder;
        std::unique_ptr<arrow::UInt64Builder> par_value_builder;
        std::unique_ptr<arrow::StringBuilder> quantity_notation_builder;
        std::unique_ptr<arrow::UInt8Builder> inst_unit_exp_builder;
        std::unique_ptr<arrow::StringBuilder> settlement_delay_builder;
        std::unique_ptr<arrow::StringBuilder> strike_currency_builder;
        std::unique_ptr<arrow::UInt8Builder> tax_code_builder;
        std::unique_ptr<arrow::StringBuilder> type_of_corporate_event_builder;
        std::unique_ptr<arrow::StringBuilder> type_of_market_admission_builder;
        std::unique_ptr<arrow::UInt8Builder> repo_indicator_builder;
        std::unique_ptr<arrow::Int64Builder> issue_price_builder;
        std::unique_ptr<arrow::StringBuilder> nominal_currency_builder;
        std::unique_ptr<arrow::UInt8Builder> issue_price_decimals_builder;
        std::unique_ptr<arrow::UInt8Builder> strike_price_decimals_builder;
        std::unique_ptr<arrow::UInt8Builder> liquid_instrument_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> icb_code_builder;
        std::unique_ptr<arrow::UInt64Builder> threshold_lis_post_trade_60mn_builder;
        std::unique_ptr<arrow::UInt64Builder> threshold_lis_post_trade_120mn_builder;
        std::unique_ptr<arrow::UInt64Builder> threshold_lis_post_trade_eod_builder;
        std::unique_ptr<arrow::StringBuilder> long_mnemonic_builder;
        std::unique_ptr<arrow::UInt64Builder> max_order_amount_call_builder;
        std::unique_ptr<arrow::UInt64Builder> max_order_amount_continuous_builder;
        std::unique_ptr<arrow::UInt64Builder> max_order_quantity_call_builder;
        std::unique_ptr<arrow::UInt64Builder> max_order_quantity_continuous_builder;
        std::unique_ptr<arrow::UInt32Builder> pool_factor_builder;
        std::unique_ptr<arrow::StringBuilder> emm_pattern_rep_group_builder;
        std::unique_ptr<arrow::Int64Builder> index_level_builder;
        std::unique_ptr<arrow::UInt64Builder> pctg_of_capitalization_builder;
        std::unique_ptr<arrow::Int64Builder> prct_varfrom_prev_close_builder;
        std::unique_ptr<arrow::UInt16Builder> num_traded_instruments_builder;
        std::unique_ptr<arrow::UInt8Builder> index_level_type_builder;
        std::unique_ptr<arrow::UInt8Builder> index_price_code_builder;
        std::unique_ptr<arrow::StringBuilder> new_stats_group_builder;
        std::unique_ptr<arrow::Int64Builder> opening_level_builder;
        std::unique_ptr<arrow::Time64Builder> opening_time_builder;
        std::unique_ptr<arrow::Int64Builder> confirmed_reference_level_builder;
        std::unique_ptr<arrow::Time64Builder> confirmed_reference_time_builder;
        std::unique_ptr<arrow::Int64Builder> closing_reference_level_builder;
        std::unique_ptr<arrow::UInt64Builder> closing_reference_time_builder;
        std::unique_ptr<arrow::Int64Builder> high_level_builder;
        std::unique_ptr<arrow::Time64Builder> high_time_builder;
        std::unique_ptr<arrow::Int64Builder> low_level_builder;
        std::unique_ptr<arrow::Time64Builder> low_time_builder;
        std::unique_ptr<arrow::Int64Builder> liquidation_level_builder;
        std::unique_ptr<arrow::UInt64Builder> liquidation_time_builder;
        std::unique_ptr<arrow::StringBuilder> derivatives_instrument_trading_code_builder;
        std::unique_ptr<arrow::StringBuilder> exchange_code_builder;
        std::unique_ptr<arrow::StringBuilder> maturity_date_builder;
        std::unique_ptr<arrow::StringBuilder> strategy_code_builder;
        std::unique_ptr<arrow::UInt32Builder> contract_symbol_index_builder;
        std::unique_ptr<arrow::StringBuilder> cfi_optional_builder;
        std::unique_ptr<arrow::StringBuilder> strategy_standing_data_group_builder;
        std::unique_ptr<arrow::UInt16Builder> contract_event_date_builder;
        std::unique_ptr<arrow::UInt8Builder> exer_style_builder;
        std::unique_ptr<arrow::StringBuilder> contract_name_builder;
        std::unique_ptr<arrow::StringBuilder> contract_type_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_type_builder;
        std::unique_ptr<arrow::UInt8Builder> price_decimals_optional_builder;
        std::unique_ptr<arrow::UInt8Builder> ratio_decimals_optional_builder;
        std::unique_ptr<arrow::StringBuilder> country_of_exchange_builder;
        std::unique_ptr<arrow::StringBuilder> product_code_builder;
        std::unique_ptr<arrow::UInt32Builder> underlying_expiry_builder;
        std::unique_ptr<arrow::StringBuilder> settlement_method_builder;
        std::unique_ptr<arrow::StringBuilder> trading_currency_builder;
        std::unique_ptr<arrow::UInt8Builder> strike_price_decimals_ratio_builder;
        std::unique_ptr<arrow::UInt8Builder> contract_trading_type_builder;
        std::unique_ptr<arrow::UInt8Builder> underlying_subtype_builder;
        std::unique_ptr<arrow::StringBuilder> mother_stock_isin_builder;
        std::unique_ptr<arrow::UInt64Builder> settlement_tick_size_builder;
        std::unique_ptr<arrow::UInt64Builder> edsp_tick_size_builder;
        std::unique_ptr<arrow::UInt32Builder> underlying_symbol_index_builder;
        std::unique_ptr<arrow::UInt8Builder> trading_policy_builder;
        std::unique_ptr<arrow::UInt16Builder> reference_spread_table_id_builder;
        std::unique_ptr<arrow::UInt8Builder> derivatives_market_model_builder;
        std::unique_ptr<arrow::UInt64Builder> trading_unit_builder;
        std::unique_ptr<arrow::UInt8Builder> reference_price_origin_in_opening_call_builder;
        std::unique_ptr<arrow::UInt8Builder> reference_price_origin_in_continuous_builder;
        std::unique_ptr<arrow::UInt8Builder> reference_price_origin_in_trading_interruption_builder;
        std::unique_ptr<arrow::UInt8Builder> collar_expansion_factor_builder;
        std::unique_ptr<arrow::UInt8Builder> mifidii_liquid_flag_builder;
        std::unique_ptr<arrow::UInt8Builder> pricing_algorithm_builder;
        std::unique_ptr<arrow::StringBuilder> contract_emm_properties_group_builder;
        std::unique_ptr<arrow::UInt64Builder> lot_size_builder;
        std::unique_ptr<arrow::UInt16Builder> last_trading_date_builder;
        std::unique_ptr<arrow::UInt16Builder> days_to_expiry_builder;
        std::unique_ptr<arrow::StringBuilder> derivatives_instrument_trading_code_optional_builder;
        std::unique_ptr<arrow::UInt8Builder> derivatives_instrument_type_builder;
        std::unique_ptr<arrow::UInt8Builder> expiry_cycle_type_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_derivatives_instrument_trading_code_builder;
        std::unique_ptr<arrow::StringBuilder> outright_rep_group_builder;
        std::unique_ptr<arrow::StringBuilder> long_order_updates_group_builder;
        std::unique_ptr<arrow::StringBuilder> package_components_group_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_instrument_id_type_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_instrument_id_builder;
        std::unique_ptr<arrow::StringBuilder> currency_builder;
        std::unique_ptr<arrow::StringBuilder> lei_code_builder;
        std::unique_ptr<arrow::UInt8Builder> quote_update_type_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_price_builder;
        std::unique_ptr<arrow::StringBuilder> apa_origin_builder;
        std::unique_ptr<arrow::StringBuilder> second_notional_currency_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_index_name_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_index_term_builder;
        std::unique_ptr<arrow::UInt8Builder> option_type_builder;
        std::unique_ptr<arrow::StringBuilder> expiry_date_builder;
        std::unique_ptr<arrow::StringBuilder> mifid_transaction_id_builder;
        std::unique_ptr<arrow::UInt8Builder> efficient_mmt_market_mechanism_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_trading_mode_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_transaction_category_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_negotiation_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_agency_cross_trade_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_modification_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_benchmark_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_special_dividend_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_off_book_automated_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_contributionto_price_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_algorithmic_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_publication_mode_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_post_trade_deferral_builder;
        std::unique_ptr<arrow::StringBuilder> efficient_mmt_duplicative_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> long_trade_reference_builder;
        std::unique_ptr<arrow::StringBuilder> isin_code_optional_builder;
        std::unique_ptr<arrow::StringBuilder> sedol_code_builder;
        std::unique_ptr<arrow::StringBuilder> long_issuer_name_builder;
        std::unique_ptr<arrow::StringBuilder> long_instrument_name_builder;
        std::unique_ptr<arrow::StringBuilder> currency_optional_builder;
        std::unique_ptr<arrow::UInt16Builder> date_of_initial_listing_builder;
        std::unique_ptr<arrow::Int64Builder> share_amount_in_issue_builder;
        std::unique_ptr<arrow::StringBuilder> opened_closed_fund_builder;
        std::unique_ptr<arrow::Int64Builder> last_nav_price_builder;
        std::unique_ptr<arrow::StringBuilder> gross_of_cdsc_indicator_builder;
        std::unique_ptr<arrow::Int64Builder> coupon_builder;
        std::unique_ptr<arrow::Int64Builder> closing_price_builder;
        std::unique_ptr<arrow::StringBuilder> mic_optional_builder;
        std::unique_ptr<arrow::Int64Builder> gross_dividend_payable_per_unit_builder;
        std::unique_ptr<arrow::StringBuilder> dividend_currency_builder;
        std::unique_ptr<arrow::UInt16Builder> dividend_record_date_builder;
        std::unique_ptr<arrow::UInt64Builder> dividend_rate_builder;
        std::unique_ptr<arrow::UInt16Builder> ex_dividend_date_builder;
        std::unique_ptr<arrow::UInt16Builder> dividend_payment_date_builder;
        std::unique_ptr<arrow::StringBuilder> tax_description_attaching_to_a_dividend_builder;
        std::unique_ptr<arrow::StringBuilder> next_meeting_builder;
        std::unique_ptr<arrow::Int64Builder> gross_dividend_in_euros_builder;
        std::unique_ptr<arrow::UInt16Builder> issue_date_builder;
        std::unique_ptr<arrow::UInt8Builder> payment_frequency_builder;
        std::unique_ptr<arrow::Int64Builder> minimum_amount_builder;
        std::unique_ptr<arrow::UInt8Builder> instrument_category_builder;
        std::unique_ptr<arrow::StringBuilder> security_condition_builder;
        std::unique_ptr<arrow::UInt8Builder> price_index_level_decimals_builder;
        std::unique_ptr<arrow::UInt8Builder> ratio_multiplier_decimals_builder;
        std::unique_ptr<arrow::StringBuilder> interest_payment_date_rep_group_builder;
        std::unique_ptr<arrow::UInt64Builder> bid_offer_date_time_builder;
        std::unique_ptr<arrow::StringBuilder> mmt_modification_indicator_builder;
        std::unique_ptr<arrow::Int64Builder> price_builder;
        std::unique_ptr<arrow::Int64Builder> bid_price_builder;
        std::unique_ptr<arrow::Int64Builder> offer_price_builder;
        std::unique_ptr<arrow::UInt64Builder> quantity_builder;
        std::unique_ptr<arrow::Int64Builder> notional_amount_traded_builder;
        std::unique_ptr<arrow::Int64Builder> nav_price_builder;
        std::unique_ptr<arrow::UInt64Builder> event_time_optional_builder;
        std::unique_ptr<arrow::Int64Builder> nav_bid_price_builder;
        std::unique_ptr<arrow::Int64Builder> nav_offer_price_builder;
        std::unique_ptr<arrow::UInt64Builder> last_md_seq_num_builder;
        std::unique_ptr<arrow::UInt64Builder> snapshot_time_builder;
};
}
