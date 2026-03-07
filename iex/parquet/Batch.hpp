#pragma once

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/util/byte_size.h>
#include <parquet/arrow/writer.h>

#include "Record.hpp"

namespace iex {
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
        ARROW_RETURN_NOT_OK(record.system_event.append(*system_event_builder));
        ARROW_RETURN_NOT_OK(record.timestamp.append(*timestamp_builder));
        ARROW_RETURN_NOT_OK(record.symbol.append(*symbol_builder));
        ARROW_RETURN_NOT_OK(record.round_lot_size.append(*round_lot_size_builder));
        ARROW_RETURN_NOT_OK(record.adjusted_poc_price.append(*adjusted_poc_price_builder));
        ARROW_RETURN_NOT_OK(record.luld_tier.append(*luld_tier_builder));
        ARROW_RETURN_NOT_OK(record.trading_status.append(*trading_status_builder));
        ARROW_RETURN_NOT_OK(record.reason.append(*reason_builder));
        ARROW_RETURN_NOT_OK(record.retail_liquidity_indicator.append(*retail_liquidity_indicator_builder));
        ARROW_RETURN_NOT_OK(record.operational_halt_status.append(*operational_halt_status_builder));
        ARROW_RETURN_NOT_OK(record.short_sale_price_test_status.append(*short_sale_price_test_status_builder));
        ARROW_RETURN_NOT_OK(record.detail.append(*detail_builder));
        ARROW_RETURN_NOT_OK(record.bid_size.append(*bid_size_builder));
        ARROW_RETURN_NOT_OK(record.bid_price.append(*bid_price_builder));
        ARROW_RETURN_NOT_OK(record.ask_price.append(*ask_price_builder));
        ARROW_RETURN_NOT_OK(record.ask_size.append(*ask_size_builder));
        ARROW_RETURN_NOT_OK(record.size.append(*size_builder));
        ARROW_RETURN_NOT_OK(record.price.append(*price_builder));
        ARROW_RETURN_NOT_OK(record.trade_id.append(*trade_id_builder));
        ARROW_RETURN_NOT_OK(record.price_type.append(*price_type_builder));
        ARROW_RETURN_NOT_OK(record.official_price.append(*official_price_builder));
        ARROW_RETURN_NOT_OK(record.auction_type.append(*auction_type_builder));
        ARROW_RETURN_NOT_OK(record.paired_shares.append(*paired_shares_builder));
        ARROW_RETURN_NOT_OK(record.reference_price.append(*reference_price_builder));
        ARROW_RETURN_NOT_OK(record.indicative_clearing_price.append(*indicative_clearing_price_builder));
        ARROW_RETURN_NOT_OK(record.imbalance_shares.append(*imbalance_shares_builder));
        ARROW_RETURN_NOT_OK(record.imbalance_side.append(*imbalance_side_builder));
        ARROW_RETURN_NOT_OK(record.extension_number.append(*extension_number_builder));
        ARROW_RETURN_NOT_OK(record.scheduled_auction_time.append(*scheduled_auction_time_builder));
        ARROW_RETURN_NOT_OK(record.auction_book_clearing_price.append(*auction_book_clearing_price_builder));
        ARROW_RETURN_NOT_OK(record.collar_reference_price.append(*collar_reference_price_builder));
        ARROW_RETURN_NOT_OK(record.lower_auction_collar.append(*lower_auction_collar_builder));
        ARROW_RETURN_NOT_OK(record.upper_auction_collar.append(*upper_auction_collar_builder));

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
        std::shared_ptr<arrow::Array> system_event_column;
        std::shared_ptr<arrow::Array> timestamp_column;
        std::shared_ptr<arrow::Array> symbol_column;
        std::shared_ptr<arrow::Array> round_lot_size_column;
        std::shared_ptr<arrow::Array> adjusted_poc_price_column;
        std::shared_ptr<arrow::Array> luld_tier_column;
        std::shared_ptr<arrow::Array> trading_status_column;
        std::shared_ptr<arrow::Array> reason_column;
        std::shared_ptr<arrow::Array> retail_liquidity_indicator_column;
        std::shared_ptr<arrow::Array> operational_halt_status_column;
        std::shared_ptr<arrow::Array> short_sale_price_test_status_column;
        std::shared_ptr<arrow::Array> detail_column;
        std::shared_ptr<arrow::Array> bid_size_column;
        std::shared_ptr<arrow::Array> bid_price_column;
        std::shared_ptr<arrow::Array> ask_price_column;
        std::shared_ptr<arrow::Array> ask_size_column;
        std::shared_ptr<arrow::Array> size_column;
        std::shared_ptr<arrow::Array> price_column;
        std::shared_ptr<arrow::Array> trade_id_column;
        std::shared_ptr<arrow::Array> price_type_column;
        std::shared_ptr<arrow::Array> official_price_column;
        std::shared_ptr<arrow::Array> auction_type_column;
        std::shared_ptr<arrow::Array> paired_shares_column;
        std::shared_ptr<arrow::Array> reference_price_column;
        std::shared_ptr<arrow::Array> indicative_clearing_price_column;
        std::shared_ptr<arrow::Array> imbalance_shares_column;
        std::shared_ptr<arrow::Array> imbalance_side_column;
        std::shared_ptr<arrow::Array> extension_number_column;
        std::shared_ptr<arrow::Array> scheduled_auction_time_column;
        std::shared_ptr<arrow::Array> auction_book_clearing_price_column;
        std::shared_ptr<arrow::Array> collar_reference_price_column;
        std::shared_ptr<arrow::Array> lower_auction_collar_column;
        std::shared_ptr<arrow::Array> upper_auction_collar_column;

        ARROW_RETURN_NOT_OK(event_type_builder->Finish(&event_type_column));
        ARROW_RETURN_NOT_OK(system_event_builder->Finish(&system_event_column));
        ARROW_RETURN_NOT_OK(timestamp_builder->Finish(&timestamp_column));
        ARROW_RETURN_NOT_OK(symbol_builder->Finish(&symbol_column));
        ARROW_RETURN_NOT_OK(round_lot_size_builder->Finish(&round_lot_size_column));
        ARROW_RETURN_NOT_OK(adjusted_poc_price_builder->Finish(&adjusted_poc_price_column));
        ARROW_RETURN_NOT_OK(luld_tier_builder->Finish(&luld_tier_column));
        ARROW_RETURN_NOT_OK(trading_status_builder->Finish(&trading_status_column));
        ARROW_RETURN_NOT_OK(reason_builder->Finish(&reason_column));
        ARROW_RETURN_NOT_OK(retail_liquidity_indicator_builder->Finish(&retail_liquidity_indicator_column));
        ARROW_RETURN_NOT_OK(operational_halt_status_builder->Finish(&operational_halt_status_column));
        ARROW_RETURN_NOT_OK(short_sale_price_test_status_builder->Finish(&short_sale_price_test_status_column));
        ARROW_RETURN_NOT_OK(detail_builder->Finish(&detail_column));
        ARROW_RETURN_NOT_OK(bid_size_builder->Finish(&bid_size_column));
        ARROW_RETURN_NOT_OK(bid_price_builder->Finish(&bid_price_column));
        ARROW_RETURN_NOT_OK(ask_price_builder->Finish(&ask_price_column));
        ARROW_RETURN_NOT_OK(ask_size_builder->Finish(&ask_size_column));
        ARROW_RETURN_NOT_OK(size_builder->Finish(&size_column));
        ARROW_RETURN_NOT_OK(price_builder->Finish(&price_column));
        ARROW_RETURN_NOT_OK(trade_id_builder->Finish(&trade_id_column));
        ARROW_RETURN_NOT_OK(price_type_builder->Finish(&price_type_column));
        ARROW_RETURN_NOT_OK(official_price_builder->Finish(&official_price_column));
        ARROW_RETURN_NOT_OK(auction_type_builder->Finish(&auction_type_column));
        ARROW_RETURN_NOT_OK(paired_shares_builder->Finish(&paired_shares_column));
        ARROW_RETURN_NOT_OK(reference_price_builder->Finish(&reference_price_column));
        ARROW_RETURN_NOT_OK(indicative_clearing_price_builder->Finish(&indicative_clearing_price_column));
        ARROW_RETURN_NOT_OK(imbalance_shares_builder->Finish(&imbalance_shares_column));
        ARROW_RETURN_NOT_OK(imbalance_side_builder->Finish(&imbalance_side_column));
        ARROW_RETURN_NOT_OK(extension_number_builder->Finish(&extension_number_column));
        ARROW_RETURN_NOT_OK(scheduled_auction_time_builder->Finish(&scheduled_auction_time_column));
        ARROW_RETURN_NOT_OK(auction_book_clearing_price_builder->Finish(&auction_book_clearing_price_column));
        ARROW_RETURN_NOT_OK(collar_reference_price_builder->Finish(&collar_reference_price_column));
        ARROW_RETURN_NOT_OK(lower_auction_collar_builder->Finish(&lower_auction_collar_column));
        ARROW_RETURN_NOT_OK(upper_auction_collar_builder->Finish(&upper_auction_collar_column));

        auto batch = arrow::RecordBatch::Make(schema_, row_count_, {
            event_type_column,
            system_event_column,
            timestamp_column,
            symbol_column,
            round_lot_size_column,
            adjusted_poc_price_column,
            luld_tier_column,
            trading_status_column,
            reason_column,
            retail_liquidity_indicator_column,
            operational_halt_status_column,
            short_sale_price_test_status_column,
            detail_column,
            bid_size_column,
            bid_price_column,
            ask_price_column,
            ask_size_column,
            size_column,
            price_column,
            trade_id_column,
            price_type_column,
            official_price_column,
            auction_type_column,
            paired_shares_column,
            reference_price_column,
            indicative_clearing_price_column,
            imbalance_shares_column,
            imbalance_side_column,
            extension_number_column,
            scheduled_auction_time_column,
            auction_book_clearing_price_column,
            collar_reference_price_column,
            lower_auction_collar_column,
            upper_auction_collar_column,
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
        system_event_builder = std::make_unique<arrow::StringBuilder>();
        timestamp_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        symbol_builder = std::make_unique<arrow::StringBuilder>();
        round_lot_size_builder = std::make_unique<arrow::UInt32Builder>();
        adjusted_poc_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(AdjustedPocPrice::precision, AdjustedPocPrice::scale));
        luld_tier_builder = std::make_unique<arrow::UInt8Builder>();
        trading_status_builder = std::make_unique<arrow::StringBuilder>();
        reason_builder = std::make_unique<arrow::StringBuilder>();
        retail_liquidity_indicator_builder = std::make_unique<arrow::StringBuilder>();
        operational_halt_status_builder = std::make_unique<arrow::StringBuilder>();
        short_sale_price_test_status_builder = std::make_unique<arrow::UInt8Builder>();
        detail_builder = std::make_unique<arrow::StringBuilder>();
        bid_size_builder = std::make_unique<arrow::UInt32Builder>();
        bid_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(BidPrice::precision, BidPrice::scale));
        ask_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(AskPrice::precision, AskPrice::scale));
        ask_size_builder = std::make_unique<arrow::UInt32Builder>();
        size_builder = std::make_unique<arrow::UInt32Builder>();
        price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(Price::precision, Price::scale));
        trade_id_builder = std::make_unique<arrow::UInt64Builder>();
        price_type_builder = std::make_unique<arrow::StringBuilder>();
        official_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(OfficialPrice::precision, OfficialPrice::scale));
        auction_type_builder = std::make_unique<arrow::StringBuilder>();
        paired_shares_builder = std::make_unique<arrow::UInt32Builder>();
        reference_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(ReferencePrice::precision, ReferencePrice::scale));
        indicative_clearing_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(IndicativeClearingPrice::precision, IndicativeClearingPrice::scale));
        imbalance_shares_builder = std::make_unique<arrow::UInt32Builder>();
        imbalance_side_builder = std::make_unique<arrow::StringBuilder>();
        extension_number_builder = std::make_unique<arrow::StringBuilder>();
        scheduled_auction_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
        auction_book_clearing_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(AuctionBookClearingPrice::precision, AuctionBookClearingPrice::scale));
        collar_reference_price_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(CollarReferencePrice::precision, CollarReferencePrice::scale));
        lower_auction_collar_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(LowerAuctionCollar::precision, LowerAuctionCollar::scale));
        upper_auction_collar_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(UpperAuctionCollar::precision, UpperAuctionCollar::scale));

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
        std::unique_ptr<arrow::StringBuilder> system_event_builder;
        std::unique_ptr<arrow::Time64Builder> timestamp_builder;
        std::unique_ptr<arrow::StringBuilder> symbol_builder;
        std::unique_ptr<arrow::UInt32Builder> round_lot_size_builder;
        std::unique_ptr<arrow::Decimal128Builder> adjusted_poc_price_builder;
        std::unique_ptr<arrow::UInt8Builder> luld_tier_builder;
        std::unique_ptr<arrow::StringBuilder> trading_status_builder;
        std::unique_ptr<arrow::StringBuilder> reason_builder;
        std::unique_ptr<arrow::StringBuilder> retail_liquidity_indicator_builder;
        std::unique_ptr<arrow::StringBuilder> operational_halt_status_builder;
        std::unique_ptr<arrow::UInt8Builder> short_sale_price_test_status_builder;
        std::unique_ptr<arrow::StringBuilder> detail_builder;
        std::unique_ptr<arrow::UInt32Builder> bid_size_builder;
        std::unique_ptr<arrow::Decimal128Builder> bid_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> ask_price_builder;
        std::unique_ptr<arrow::UInt32Builder> ask_size_builder;
        std::unique_ptr<arrow::UInt32Builder> size_builder;
        std::unique_ptr<arrow::Decimal128Builder> price_builder;
        std::unique_ptr<arrow::UInt64Builder> trade_id_builder;
        std::unique_ptr<arrow::StringBuilder> price_type_builder;
        std::unique_ptr<arrow::Decimal128Builder> official_price_builder;
        std::unique_ptr<arrow::StringBuilder> auction_type_builder;
        std::unique_ptr<arrow::UInt32Builder> paired_shares_builder;
        std::unique_ptr<arrow::Decimal128Builder> reference_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> indicative_clearing_price_builder;
        std::unique_ptr<arrow::UInt32Builder> imbalance_shares_builder;
        std::unique_ptr<arrow::StringBuilder> imbalance_side_builder;
        std::unique_ptr<arrow::StringBuilder> extension_number_builder;
        std::unique_ptr<arrow::Time64Builder> scheduled_auction_time_builder;
        std::unique_ptr<arrow::Decimal128Builder> auction_book_clearing_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> collar_reference_price_builder;
        std::unique_ptr<arrow::Decimal128Builder> lower_auction_collar_builder;
        std::unique_ptr<arrow::Decimal128Builder> upper_auction_collar_builder;
};
}
