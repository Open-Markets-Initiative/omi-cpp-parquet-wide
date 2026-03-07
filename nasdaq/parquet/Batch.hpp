#pragma once

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/util/byte_size.h>
#include <parquet/arrow/writer.h>

#include "Record.hpp"

namespace nasdaq {
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
        ARROW_RETURN_NOT_OK(record.stock_locate.append(*stock_locate_builder));
        ARROW_RETURN_NOT_OK(record.tracking_number.append(*tracking_number_builder));
        ARROW_RETURN_NOT_OK(record.timestamp.append(*timestamp_builder));
        ARROW_RETURN_NOT_OK(record.event_code.append(*event_code_builder));
        ARROW_RETURN_NOT_OK(record.stock.append(*stock_builder));
        ARROW_RETURN_NOT_OK(record.market_category.append(*market_category_builder));
        ARROW_RETURN_NOT_OK(record.financial_status_indicator.append(*financial_status_indicator_builder));
        ARROW_RETURN_NOT_OK(record.round_lot_size.append(*round_lot_size_builder));
        ARROW_RETURN_NOT_OK(record.round_lots_only.append(*round_lots_only_builder));
        ARROW_RETURN_NOT_OK(record.issue_classification.append(*issue_classification_builder));
        ARROW_RETURN_NOT_OK(record.issue_sub_type.append(*issue_sub_type_builder));
        ARROW_RETURN_NOT_OK(record.authenticity.append(*authenticity_builder));
        ARROW_RETURN_NOT_OK(record.short_sale_threshold_indicator.append(*short_sale_threshold_indicator_builder));
        ARROW_RETURN_NOT_OK(record.ipo_flag.append(*ipo_flag_builder));
        ARROW_RETURN_NOT_OK(record.luld_reference_price_tier.append(*luld_reference_price_tier_builder));
        ARROW_RETURN_NOT_OK(record.etp_flag.append(*etp_flag_builder));
        ARROW_RETURN_NOT_OK(record.etp_leverage_factor.append(*etp_leverage_factor_builder));
        ARROW_RETURN_NOT_OK(record.inverse_indicator.append(*inverse_indicator_builder));
        ARROW_RETURN_NOT_OK(record.trading_state.append(*trading_state_builder));
        ARROW_RETURN_NOT_OK(record.reserved.append(*reserved_builder));
        ARROW_RETURN_NOT_OK(record.reason_code.append(*reason_code_builder));
        ARROW_RETURN_NOT_OK(record.locate_code.append(*locate_code_builder));
        ARROW_RETURN_NOT_OK(record.reg_sho_action.append(*reg_sho_action_builder));
        ARROW_RETURN_NOT_OK(record.mpid.append(*mpid_builder));
        ARROW_RETURN_NOT_OK(record.primary_market_maker.append(*primary_market_maker_builder));
        ARROW_RETURN_NOT_OK(record.market_maker_mode.append(*market_maker_mode_builder));
        ARROW_RETURN_NOT_OK(record.market_participant_state.append(*market_participant_state_builder));
        ARROW_RETURN_NOT_OK(record.level_1.append(*level_1_builder));
        ARROW_RETURN_NOT_OK(record.level_2.append(*level_2_builder));
        ARROW_RETURN_NOT_OK(record.level_3.append(*level_3_builder));
        ARROW_RETURN_NOT_OK(record.breached_level.append(*breached_level_builder));
        ARROW_RETURN_NOT_OK(record.ipo_quotation_release_time.append(*ipo_quotation_release_time_builder));
        ARROW_RETURN_NOT_OK(record.ipo_quotation_release_qualifier.append(*ipo_quotation_release_qualifier_builder));
        ARROW_RETURN_NOT_OK(record.ipo_price.append(*ipo_price_builder));
        ARROW_RETURN_NOT_OK(record.auction_collar_reference_price.append(*auction_collar_reference_price_builder));
        ARROW_RETURN_NOT_OK(record.upper_auction_collar_price.append(*upper_auction_collar_price_builder));
        ARROW_RETURN_NOT_OK(record.lower_auction_collar_price.append(*lower_auction_collar_price_builder));
        ARROW_RETURN_NOT_OK(record.auction_collar_extension.append(*auction_collar_extension_builder));
        ARROW_RETURN_NOT_OK(record.market_code.append(*market_code_builder));
        ARROW_RETURN_NOT_OK(record.operational_halt_action.append(*operational_halt_action_builder));
        ARROW_RETURN_NOT_OK(record.order_reference_number.append(*order_reference_number_builder));
        ARROW_RETURN_NOT_OK(record.buy_sell_indicator.append(*buy_sell_indicator_builder));
        ARROW_RETURN_NOT_OK(record.shares.append(*shares_builder));
        ARROW_RETURN_NOT_OK(record.price.append(*price_builder));
        ARROW_RETURN_NOT_OK(record.attribution.append(*attribution_builder));
        ARROW_RETURN_NOT_OK(record.executed_shares.append(*executed_shares_builder));
        ARROW_RETURN_NOT_OK(record.match_number.append(*match_number_builder));
        ARROW_RETURN_NOT_OK(record.printable.append(*printable_builder));
        ARROW_RETURN_NOT_OK(record.execution_price.append(*execution_price_builder));
        ARROW_RETURN_NOT_OK(record.canceled_shares.append(*canceled_shares_builder));
        ARROW_RETURN_NOT_OK(record.original_order_reference_number.append(*original_order_reference_number_builder));
        ARROW_RETURN_NOT_OK(record.new_order_reference_number.append(*new_order_reference_number_builder));
        ARROW_RETURN_NOT_OK(record.cross_shares.append(*cross_shares_builder));
        ARROW_RETURN_NOT_OK(record.cross_price.append(*cross_price_builder));
        ARROW_RETURN_NOT_OK(record.cross_type.append(*cross_type_builder));
        ARROW_RETURN_NOT_OK(record.paired_shares.append(*paired_shares_builder));
        ARROW_RETURN_NOT_OK(record.imbalance_shares.append(*imbalance_shares_builder));
        ARROW_RETURN_NOT_OK(record.imbalance_direction.append(*imbalance_direction_builder));
        ARROW_RETURN_NOT_OK(record.far_price.append(*far_price_builder));
        ARROW_RETURN_NOT_OK(record.near_price.append(*near_price_builder));
        ARROW_RETURN_NOT_OK(record.current_reference_price.append(*current_reference_price_builder));
        ARROW_RETURN_NOT_OK(record.price_variation_indicator.append(*price_variation_indicator_builder));
        ARROW_RETURN_NOT_OK(record.interest_flag.append(*interest_flag_builder));
        ARROW_RETURN_NOT_OK(record.open_eligibility_status.append(*open_eligibility_status_builder));
        ARROW_RETURN_NOT_OK(record.minimum_allowable_price.append(*minimum_allowable_price_builder));
        ARROW_RETURN_NOT_OK(record.maximum_allowable_price.append(*maximum_allowable_price_builder));
        ARROW_RETURN_NOT_OK(record.near_execution_price.append(*near_execution_price_builder));
        ARROW_RETURN_NOT_OK(record.near_execution_time.append(*near_execution_time_builder));
        ARROW_RETURN_NOT_OK(record.lower_price_range_collar.append(*lower_price_range_collar_builder));
        ARROW_RETURN_NOT_OK(record.upper_price_range_collar.append(*upper_price_range_collar_builder));

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
        std::shared_ptr<arrow::Array> stock_locate_column;
        std::shared_ptr<arrow::Array> tracking_number_column;
        std::shared_ptr<arrow::Array> timestamp_column;
        std::shared_ptr<arrow::Array> event_code_column;
        std::shared_ptr<arrow::Array> stock_column;
        std::shared_ptr<arrow::Array> market_category_column;
        std::shared_ptr<arrow::Array> financial_status_indicator_column;
        std::shared_ptr<arrow::Array> round_lot_size_column;
        std::shared_ptr<arrow::Array> round_lots_only_column;
        std::shared_ptr<arrow::Array> issue_classification_column;
        std::shared_ptr<arrow::Array> issue_sub_type_column;
        std::shared_ptr<arrow::Array> authenticity_column;
        std::shared_ptr<arrow::Array> short_sale_threshold_indicator_column;
        std::shared_ptr<arrow::Array> ipo_flag_column;
        std::shared_ptr<arrow::Array> luld_reference_price_tier_column;
        std::shared_ptr<arrow::Array> etp_flag_column;
        std::shared_ptr<arrow::Array> etp_leverage_factor_column;
        std::shared_ptr<arrow::Array> inverse_indicator_column;
        std::shared_ptr<arrow::Array> trading_state_column;
        std::shared_ptr<arrow::Array> reserved_column;
        std::shared_ptr<arrow::Array> reason_code_column;
        std::shared_ptr<arrow::Array> locate_code_column;
        std::shared_ptr<arrow::Array> reg_sho_action_column;
        std::shared_ptr<arrow::Array> mpid_column;
        std::shared_ptr<arrow::Array> primary_market_maker_column;
        std::shared_ptr<arrow::Array> market_maker_mode_column;
        std::shared_ptr<arrow::Array> market_participant_state_column;
        std::shared_ptr<arrow::Array> level_1_column;
        std::shared_ptr<arrow::Array> level_2_column;
        std::shared_ptr<arrow::Array> level_3_column;
        std::shared_ptr<arrow::Array> breached_level_column;
        std::shared_ptr<arrow::Array> ipo_quotation_release_time_column;
        std::shared_ptr<arrow::Array> ipo_quotation_release_qualifier_column;
        std::shared_ptr<arrow::Array> ipo_price_column;
        std::shared_ptr<arrow::Array> auction_collar_reference_price_column;
        std::shared_ptr<arrow::Array> upper_auction_collar_price_column;
        std::shared_ptr<arrow::Array> lower_auction_collar_price_column;
        std::shared_ptr<arrow::Array> auction_collar_extension_column;
        std::shared_ptr<arrow::Array> market_code_column;
        std::shared_ptr<arrow::Array> operational_halt_action_column;
        std::shared_ptr<arrow::Array> order_reference_number_column;
        std::shared_ptr<arrow::Array> buy_sell_indicator_column;
        std::shared_ptr<arrow::Array> shares_column;
        std::shared_ptr<arrow::Array> price_column;
        std::shared_ptr<arrow::Array> attribution_column;
        std::shared_ptr<arrow::Array> executed_shares_column;
        std::shared_ptr<arrow::Array> match_number_column;
        std::shared_ptr<arrow::Array> printable_column;
        std::shared_ptr<arrow::Array> execution_price_column;
        std::shared_ptr<arrow::Array> canceled_shares_column;
        std::shared_ptr<arrow::Array> original_order_reference_number_column;
        std::shared_ptr<arrow::Array> new_order_reference_number_column;
        std::shared_ptr<arrow::Array> cross_shares_column;
        std::shared_ptr<arrow::Array> cross_price_column;
        std::shared_ptr<arrow::Array> cross_type_column;
        std::shared_ptr<arrow::Array> paired_shares_column;
        std::shared_ptr<arrow::Array> imbalance_shares_column;
        std::shared_ptr<arrow::Array> imbalance_direction_column;
        std::shared_ptr<arrow::Array> far_price_column;
        std::shared_ptr<arrow::Array> near_price_column;
        std::shared_ptr<arrow::Array> current_reference_price_column;
        std::shared_ptr<arrow::Array> price_variation_indicator_column;
        std::shared_ptr<arrow::Array> interest_flag_column;
        std::shared_ptr<arrow::Array> open_eligibility_status_column;
        std::shared_ptr<arrow::Array> minimum_allowable_price_column;
        std::shared_ptr<arrow::Array> maximum_allowable_price_column;
        std::shared_ptr<arrow::Array> near_execution_price_column;
        std::shared_ptr<arrow::Array> near_execution_time_column;
        std::shared_ptr<arrow::Array> lower_price_range_collar_column;
        std::shared_ptr<arrow::Array> upper_price_range_collar_column;

        ARROW_RETURN_NOT_OK(event_type_builder->Finish(&event_type_column));
        ARROW_RETURN_NOT_OK(stock_locate_builder->Finish(&stock_locate_column));
        ARROW_RETURN_NOT_OK(tracking_number_builder->Finish(&tracking_number_column));
        ARROW_RETURN_NOT_OK(timestamp_builder->Finish(&timestamp_column));
        ARROW_RETURN_NOT_OK(event_code_builder->Finish(&event_code_column));
        ARROW_RETURN_NOT_OK(stock_builder->Finish(&stock_column));
        ARROW_RETURN_NOT_OK(market_category_builder->Finish(&market_category_column));
        ARROW_RETURN_NOT_OK(financial_status_indicator_builder->Finish(&financial_status_indicator_column));
        ARROW_RETURN_NOT_OK(round_lot_size_builder->Finish(&round_lot_size_column));
        ARROW_RETURN_NOT_OK(round_lots_only_builder->Finish(&round_lots_only_column));
        ARROW_RETURN_NOT_OK(issue_classification_builder->Finish(&issue_classification_column));
        ARROW_RETURN_NOT_OK(issue_sub_type_builder->Finish(&issue_sub_type_column));
        ARROW_RETURN_NOT_OK(authenticity_builder->Finish(&authenticity_column));
        ARROW_RETURN_NOT_OK(short_sale_threshold_indicator_builder->Finish(&short_sale_threshold_indicator_column));
        ARROW_RETURN_NOT_OK(ipo_flag_builder->Finish(&ipo_flag_column));
        ARROW_RETURN_NOT_OK(luld_reference_price_tier_builder->Finish(&luld_reference_price_tier_column));
        ARROW_RETURN_NOT_OK(etp_flag_builder->Finish(&etp_flag_column));
        ARROW_RETURN_NOT_OK(etp_leverage_factor_builder->Finish(&etp_leverage_factor_column));
        ARROW_RETURN_NOT_OK(inverse_indicator_builder->Finish(&inverse_indicator_column));
        ARROW_RETURN_NOT_OK(trading_state_builder->Finish(&trading_state_column));
        ARROW_RETURN_NOT_OK(reserved_builder->Finish(&reserved_column));
        ARROW_RETURN_NOT_OK(reason_code_builder->Finish(&reason_code_column));
        ARROW_RETURN_NOT_OK(locate_code_builder->Finish(&locate_code_column));
        ARROW_RETURN_NOT_OK(reg_sho_action_builder->Finish(&reg_sho_action_column));
        ARROW_RETURN_NOT_OK(mpid_builder->Finish(&mpid_column));
        ARROW_RETURN_NOT_OK(primary_market_maker_builder->Finish(&primary_market_maker_column));
        ARROW_RETURN_NOT_OK(market_maker_mode_builder->Finish(&market_maker_mode_column));
        ARROW_RETURN_NOT_OK(market_participant_state_builder->Finish(&market_participant_state_column));
        ARROW_RETURN_NOT_OK(level_1_builder->Finish(&level_1_column));
        ARROW_RETURN_NOT_OK(level_2_builder->Finish(&level_2_column));
        ARROW_RETURN_NOT_OK(level_3_builder->Finish(&level_3_column));
        ARROW_RETURN_NOT_OK(breached_level_builder->Finish(&breached_level_column));
        ARROW_RETURN_NOT_OK(ipo_quotation_release_time_builder->Finish(&ipo_quotation_release_time_column));
        ARROW_RETURN_NOT_OK(ipo_quotation_release_qualifier_builder->Finish(&ipo_quotation_release_qualifier_column));
        ARROW_RETURN_NOT_OK(ipo_price_builder->Finish(&ipo_price_column));
        ARROW_RETURN_NOT_OK(auction_collar_reference_price_builder->Finish(&auction_collar_reference_price_column));
        ARROW_RETURN_NOT_OK(upper_auction_collar_price_builder->Finish(&upper_auction_collar_price_column));
        ARROW_RETURN_NOT_OK(lower_auction_collar_price_builder->Finish(&lower_auction_collar_price_column));
        ARROW_RETURN_NOT_OK(auction_collar_extension_builder->Finish(&auction_collar_extension_column));
        ARROW_RETURN_NOT_OK(market_code_builder->Finish(&market_code_column));
        ARROW_RETURN_NOT_OK(operational_halt_action_builder->Finish(&operational_halt_action_column));
        ARROW_RETURN_NOT_OK(order_reference_number_builder->Finish(&order_reference_number_column));
        ARROW_RETURN_NOT_OK(buy_sell_indicator_builder->Finish(&buy_sell_indicator_column));
        ARROW_RETURN_NOT_OK(shares_builder->Finish(&shares_column));
        ARROW_RETURN_NOT_OK(price_builder->Finish(&price_column));
        ARROW_RETURN_NOT_OK(attribution_builder->Finish(&attribution_column));
        ARROW_RETURN_NOT_OK(executed_shares_builder->Finish(&executed_shares_column));
        ARROW_RETURN_NOT_OK(match_number_builder->Finish(&match_number_column));
        ARROW_RETURN_NOT_OK(printable_builder->Finish(&printable_column));
        ARROW_RETURN_NOT_OK(execution_price_builder->Finish(&execution_price_column));
        ARROW_RETURN_NOT_OK(canceled_shares_builder->Finish(&canceled_shares_column));
        ARROW_RETURN_NOT_OK(original_order_reference_number_builder->Finish(&original_order_reference_number_column));
        ARROW_RETURN_NOT_OK(new_order_reference_number_builder->Finish(&new_order_reference_number_column));
        ARROW_RETURN_NOT_OK(cross_shares_builder->Finish(&cross_shares_column));
        ARROW_RETURN_NOT_OK(cross_price_builder->Finish(&cross_price_column));
        ARROW_RETURN_NOT_OK(cross_type_builder->Finish(&cross_type_column));
        ARROW_RETURN_NOT_OK(paired_shares_builder->Finish(&paired_shares_column));
        ARROW_RETURN_NOT_OK(imbalance_shares_builder->Finish(&imbalance_shares_column));
        ARROW_RETURN_NOT_OK(imbalance_direction_builder->Finish(&imbalance_direction_column));
        ARROW_RETURN_NOT_OK(far_price_builder->Finish(&far_price_column));
        ARROW_RETURN_NOT_OK(near_price_builder->Finish(&near_price_column));
        ARROW_RETURN_NOT_OK(current_reference_price_builder->Finish(&current_reference_price_column));
        ARROW_RETURN_NOT_OK(price_variation_indicator_builder->Finish(&price_variation_indicator_column));
        ARROW_RETURN_NOT_OK(interest_flag_builder->Finish(&interest_flag_column));
        ARROW_RETURN_NOT_OK(open_eligibility_status_builder->Finish(&open_eligibility_status_column));
        ARROW_RETURN_NOT_OK(minimum_allowable_price_builder->Finish(&minimum_allowable_price_column));
        ARROW_RETURN_NOT_OK(maximum_allowable_price_builder->Finish(&maximum_allowable_price_column));
        ARROW_RETURN_NOT_OK(near_execution_price_builder->Finish(&near_execution_price_column));
        ARROW_RETURN_NOT_OK(near_execution_time_builder->Finish(&near_execution_time_column));
        ARROW_RETURN_NOT_OK(lower_price_range_collar_builder->Finish(&lower_price_range_collar_column));
        ARROW_RETURN_NOT_OK(upper_price_range_collar_builder->Finish(&upper_price_range_collar_column));

        auto batch = arrow::RecordBatch::Make(schema_, row_count_, {
            event_type_column,
            stock_locate_column,
            tracking_number_column,
            timestamp_column,
            event_code_column,
            stock_column,
            market_category_column,
            financial_status_indicator_column,
            round_lot_size_column,
            round_lots_only_column,
            issue_classification_column,
            issue_sub_type_column,
            authenticity_column,
            short_sale_threshold_indicator_column,
            ipo_flag_column,
            luld_reference_price_tier_column,
            etp_flag_column,
            etp_leverage_factor_column,
            inverse_indicator_column,
            trading_state_column,
            reserved_column,
            reason_code_column,
            locate_code_column,
            reg_sho_action_column,
            mpid_column,
            primary_market_maker_column,
            market_maker_mode_column,
            market_participant_state_column,
            level_1_column,
            level_2_column,
            level_3_column,
            breached_level_column,
            ipo_quotation_release_time_column,
            ipo_quotation_release_qualifier_column,
            ipo_price_column,
            auction_collar_reference_price_column,
            upper_auction_collar_price_column,
            lower_auction_collar_price_column,
            auction_collar_extension_column,
            market_code_column,
            operational_halt_action_column,
            order_reference_number_column,
            buy_sell_indicator_column,
            shares_column,
            price_column,
            attribution_column,
            executed_shares_column,
            match_number_column,
            printable_column,
            execution_price_column,
            canceled_shares_column,
            original_order_reference_number_column,
            new_order_reference_number_column,
            cross_shares_column,
            cross_price_column,
            cross_type_column,
            paired_shares_column,
            imbalance_shares_column,
            imbalance_direction_column,
            far_price_column,
            near_price_column,
            current_reference_price_column,
            price_variation_indicator_column,
            interest_flag_column,
            open_eligibility_status_column,
            minimum_allowable_price_column,
            maximum_allowable_price_column,
            near_execution_price_column,
            near_execution_time_column,
            lower_price_range_collar_column,
            upper_price_range_collar_column,
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
        stock_locate_builder = std::make_unique<arrow::UInt16Builder>();
        tracking_number_builder = std::make_unique<arrow::UInt16Builder>();
        timestamp_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        event_code_builder = std::make_unique<arrow::StringBuilder>();
        stock_builder = std::make_unique<arrow::StringBuilder>();
        market_category_builder = std::make_unique<arrow::StringBuilder>();
        financial_status_indicator_builder = std::make_unique<arrow::StringBuilder>();
        round_lot_size_builder = std::make_unique<arrow::UInt32Builder>();
        round_lots_only_builder = std::make_unique<arrow::StringBuilder>();
        issue_classification_builder = std::make_unique<arrow::StringBuilder>();
        issue_sub_type_builder = std::make_unique<arrow::StringBuilder>();
        authenticity_builder = std::make_unique<arrow::StringBuilder>();
        short_sale_threshold_indicator_builder = std::make_unique<arrow::StringBuilder>();
        ipo_flag_builder = std::make_unique<arrow::StringBuilder>();
        luld_reference_price_tier_builder = std::make_unique<arrow::StringBuilder>();
        etp_flag_builder = std::make_unique<arrow::StringBuilder>();
        etp_leverage_factor_builder = std::make_unique<arrow::UInt32Builder>();
        inverse_indicator_builder = std::make_unique<arrow::StringBuilder>();
        trading_state_builder = std::make_unique<arrow::StringBuilder>();
        reserved_builder = std::make_unique<arrow::StringBuilder>();
        reason_code_builder = std::make_unique<arrow::StringBuilder>();
        locate_code_builder = std::make_unique<arrow::UInt16Builder>();
        reg_sho_action_builder = std::make_unique<arrow::StringBuilder>();
        mpid_builder = std::make_unique<arrow::StringBuilder>();
        primary_market_maker_builder = std::make_unique<arrow::StringBuilder>();
        market_maker_mode_builder = std::make_unique<arrow::StringBuilder>();
        market_participant_state_builder = std::make_unique<arrow::StringBuilder>();
        level_1_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(Level1::precision, Level1::scale));
        level_2_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(Level2::precision, Level2::scale));
        level_3_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(Level3::precision, Level3::scale));
        breached_level_builder = std::make_unique<arrow::StringBuilder>();
        ipo_quotation_release_time_builder = std::make_unique<arrow::UInt32Builder>();
        ipo_quotation_release_qualifier_builder = std::make_unique<arrow::StringBuilder>();
        ipo_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(IpoPrice::precision, IpoPrice::scale));
        auction_collar_reference_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(AuctionCollarReferencePrice::precision, AuctionCollarReferencePrice::scale));
        upper_auction_collar_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(UpperAuctionCollarPrice::precision, UpperAuctionCollarPrice::scale));
        lower_auction_collar_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(LowerAuctionCollarPrice::precision, LowerAuctionCollarPrice::scale));
        auction_collar_extension_builder = std::make_unique<arrow::UInt32Builder>();
        market_code_builder = std::make_unique<arrow::StringBuilder>();
        operational_halt_action_builder = std::make_unique<arrow::StringBuilder>();
        order_reference_number_builder = std::make_unique<arrow::UInt64Builder>();
        buy_sell_indicator_builder = std::make_unique<arrow::StringBuilder>();
        shares_builder = std::make_unique<arrow::UInt32Builder>();
        price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(Price::precision, Price::scale));
        attribution_builder = std::make_unique<arrow::StringBuilder>();
        executed_shares_builder = std::make_unique<arrow::UInt32Builder>();
        match_number_builder = std::make_unique<arrow::UInt64Builder>();
        printable_builder = std::make_unique<arrow::StringBuilder>();
        execution_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(ExecutionPrice::precision, ExecutionPrice::scale));
        canceled_shares_builder = std::make_unique<arrow::UInt32Builder>();
        original_order_reference_number_builder = std::make_unique<arrow::UInt64Builder>();
        new_order_reference_number_builder = std::make_unique<arrow::UInt64Builder>();
        cross_shares_builder = std::make_unique<arrow::UInt64Builder>();
        cross_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(CrossPrice::precision, CrossPrice::scale));
        cross_type_builder = std::make_unique<arrow::StringBuilder>();
        paired_shares_builder = std::make_unique<arrow::UInt64Builder>();
        imbalance_shares_builder = std::make_unique<arrow::UInt64Builder>();
        imbalance_direction_builder = std::make_unique<arrow::StringBuilder>();
        far_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(FarPrice::precision, FarPrice::scale));
        near_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(NearPrice::precision, NearPrice::scale));
        current_reference_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(CurrentReferencePrice::precision, CurrentReferencePrice::scale));
        price_variation_indicator_builder = std::make_unique<arrow::StringBuilder>();
        interest_flag_builder = std::make_unique<arrow::StringBuilder>();
        open_eligibility_status_builder = std::make_unique<arrow::StringBuilder>();
        minimum_allowable_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MinimumAllowablePrice::precision, MinimumAllowablePrice::scale));
        maximum_allowable_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(MaximumAllowablePrice::precision, MaximumAllowablePrice::scale));
        near_execution_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(NearExecutionPrice::precision, NearExecutionPrice::scale));
        near_execution_time_builder = std::make_unique<arrow::UInt64Builder>();
        lower_price_range_collar_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(LowerPriceRangeCollar::precision, LowerPriceRangeCollar::scale));
        upper_price_range_collar_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(UpperPriceRangeCollar::precision, UpperPriceRangeCollar::scale));

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
        std::unique_ptr<arrow::UInt16Builder> stock_locate_builder;
        std::unique_ptr<arrow::UInt16Builder> tracking_number_builder;
        std::unique_ptr<arrow::Time64Builder> timestamp_builder;
        std::unique_ptr<arrow::StringBuilder> event_code_builder;
        std::unique_ptr<arrow::StringBuilder> stock_builder;
        std::unique_ptr<arrow::StringBuilder> market_category_builder;
        std::unique_ptr<arrow::StringBuilder> financial_status_indicator_builder;
        std::unique_ptr<arrow::UInt32Builder> round_lot_size_builder;
        std::unique_ptr<arrow::StringBuilder> round_lots_only_builder;
        std::unique_ptr<arrow::StringBuilder> issue_classification_builder;
        std::unique_ptr<arrow::StringBuilder> issue_sub_type_builder;
        std::unique_ptr<arrow::StringBuilder> authenticity_builder;
        std::unique_ptr<arrow::StringBuilder> short_sale_threshold_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> ipo_flag_builder;
        std::unique_ptr<arrow::StringBuilder> luld_reference_price_tier_builder;
        std::unique_ptr<arrow::StringBuilder> etp_flag_builder;
        std::unique_ptr<arrow::UInt32Builder> etp_leverage_factor_builder;
        std::unique_ptr<arrow::StringBuilder> inverse_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> trading_state_builder;
        std::unique_ptr<arrow::StringBuilder> reserved_builder;
        std::unique_ptr<arrow::StringBuilder> reason_code_builder;
        std::unique_ptr<arrow::UInt16Builder> locate_code_builder;
        std::unique_ptr<arrow::StringBuilder> reg_sho_action_builder;
        std::unique_ptr<arrow::StringBuilder> mpid_builder;
        std::unique_ptr<arrow::StringBuilder> primary_market_maker_builder;
        std::unique_ptr<arrow::StringBuilder> market_maker_mode_builder;
        std::unique_ptr<arrow::StringBuilder> market_participant_state_builder;
        std::unique_ptr<arrow::Decimal128Builder> level_1_builder;
        std::unique_ptr<arrow::Decimal128Builder> level_2_builder;
        std::unique_ptr<arrow::Decimal128Builder> level_3_builder;
        std::unique_ptr<arrow::StringBuilder> breached_level_builder;
        std::unique_ptr<arrow::UInt32Builder> ipo_quotation_release_time_builder;
        std::unique_ptr<arrow::StringBuilder> ipo_quotation_release_qualifier_builder;
        std::unique_ptr<arrow::Decimal128Builder> ipo_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> auction_collar_reference_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> upper_auction_collar_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> lower_auction_collar_price_builder;
        std::unique_ptr<arrow::UInt32Builder> auction_collar_extension_builder;
        std::unique_ptr<arrow::StringBuilder> market_code_builder;
        std::unique_ptr<arrow::StringBuilder> operational_halt_action_builder;
        std::unique_ptr<arrow::UInt64Builder> order_reference_number_builder;
        std::unique_ptr<arrow::StringBuilder> buy_sell_indicator_builder;
        std::unique_ptr<arrow::UInt32Builder> shares_builder;
        std::unique_ptr<arrow::Decimal128Builder> price_builder;
        std::unique_ptr<arrow::StringBuilder> attribution_builder;
        std::unique_ptr<arrow::UInt32Builder> executed_shares_builder;
        std::unique_ptr<arrow::UInt64Builder> match_number_builder;
        std::unique_ptr<arrow::StringBuilder> printable_builder;
        std::unique_ptr<arrow::Decimal128Builder> execution_price_builder;
        std::unique_ptr<arrow::UInt32Builder> canceled_shares_builder;
        std::unique_ptr<arrow::UInt64Builder> original_order_reference_number_builder;
        std::unique_ptr<arrow::UInt64Builder> new_order_reference_number_builder;
        std::unique_ptr<arrow::UInt64Builder> cross_shares_builder;
        std::unique_ptr<arrow::Decimal128Builder> cross_price_builder;
        std::unique_ptr<arrow::StringBuilder> cross_type_builder;
        std::unique_ptr<arrow::UInt64Builder> paired_shares_builder;
        std::unique_ptr<arrow::UInt64Builder> imbalance_shares_builder;
        std::unique_ptr<arrow::StringBuilder> imbalance_direction_builder;
        std::unique_ptr<arrow::Decimal128Builder> far_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> near_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> current_reference_price_builder;
        std::unique_ptr<arrow::StringBuilder> price_variation_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> interest_flag_builder;
        std::unique_ptr<arrow::StringBuilder> open_eligibility_status_builder;
        std::unique_ptr<arrow::Decimal128Builder> minimum_allowable_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> maximum_allowable_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> near_execution_price_builder;
        std::unique_ptr<arrow::UInt64Builder> near_execution_time_builder;
        std::unique_ptr<arrow::Decimal128Builder> lower_price_range_collar_builder;
        std::unique_ptr<arrow::Decimal128Builder> upper_price_range_collar_builder;
};
}
