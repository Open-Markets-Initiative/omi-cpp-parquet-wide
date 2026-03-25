#pragma once

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/util/byte_size.h>
#include <parquet/arrow/writer.h>

#include "Record.hpp"

namespace iex {
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
        ARROW_RETURN_NOT_OK(record.version.append(*version_builder));
        ARROW_RETURN_NOT_OK(record.message_protocol_id.append(*message_protocol_id_builder));
        ARROW_RETURN_NOT_OK(record.channel_id.append(*channel_id_builder));
        ARROW_RETURN_NOT_OK(record.session_id.append(*session_id_builder));
        ARROW_RETURN_NOT_OK(record.payload_length.append(*payload_length_builder));
        ARROW_RETURN_NOT_OK(record.stream_offset.append(*stream_offset_builder));
        ARROW_RETURN_NOT_OK(record.first_message_sequence_number.append(*first_message_sequence_number_builder));
        ARROW_RETURN_NOT_OK(record.send_time.append(*send_time_builder));
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
        std::shared_ptr<arrow::Array> version_column;
        std::shared_ptr<arrow::Array> message_protocol_id_column;
        std::shared_ptr<arrow::Array> channel_id_column;
        std::shared_ptr<arrow::Array> session_id_column;
        std::shared_ptr<arrow::Array> payload_length_column;
        std::shared_ptr<arrow::Array> stream_offset_column;
        std::shared_ptr<arrow::Array> first_message_sequence_number_column;
        std::shared_ptr<arrow::Array> send_time_column;
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
        ARROW_RETURN_NOT_OK(version_builder->Finish(&version_column));
        ARROW_RETURN_NOT_OK(message_protocol_id_builder->Finish(&message_protocol_id_column));
        ARROW_RETURN_NOT_OK(channel_id_builder->Finish(&channel_id_column));
        ARROW_RETURN_NOT_OK(session_id_builder->Finish(&session_id_column));
        ARROW_RETURN_NOT_OK(payload_length_builder->Finish(&payload_length_column));
        ARROW_RETURN_NOT_OK(stream_offset_builder->Finish(&stream_offset_column));
        ARROW_RETURN_NOT_OK(first_message_sequence_number_builder->Finish(&first_message_sequence_number_column));
        ARROW_RETURN_NOT_OK(send_time_builder->Finish(&send_time_column));
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

        auto batch = arrow::RecordBatch::Make(schema, row_count, {
            event_type_column,
            version_column,
            message_protocol_id_column,
            channel_id_column,
            session_id_column,
            payload_length_column,
            stream_offset_column,
            first_message_sequence_number_column,
            send_time_column,
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
        version_builder = std::make_unique<arrow::UInt8Builder>();
        message_protocol_id_builder = std::make_unique<arrow::UInt16Builder>();
        channel_id_builder = std::make_unique<arrow::UInt32Builder>();
        session_id_builder = std::make_unique<arrow::UInt32Builder>();
        payload_length_builder = std::make_unique<arrow::UInt16Builder>();
        stream_offset_builder = std::make_unique<arrow::UInt64Builder>();
        first_message_sequence_number_builder = std::make_unique<arrow::UInt64Builder>();
        send_time_builder = std::make_unique<arrow::Time64Builder>(arrow::time64(arrow::TimeUnit::NANO), arrow::default_memory_pool());
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
        std::unique_ptr<arrow::UInt8Builder> version_builder;
        std::unique_ptr<arrow::UInt16Builder> message_protocol_id_builder;
        std::unique_ptr<arrow::UInt32Builder> channel_id_builder;
        std::unique_ptr<arrow::UInt32Builder> session_id_builder;
        std::unique_ptr<arrow::UInt16Builder> payload_length_builder;
        std::unique_ptr<arrow::UInt64Builder> stream_offset_builder;
        std::unique_ptr<arrow::UInt64Builder> first_message_sequence_number_builder;
        std::unique_ptr<arrow::Time64Builder> send_time_builder;
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
