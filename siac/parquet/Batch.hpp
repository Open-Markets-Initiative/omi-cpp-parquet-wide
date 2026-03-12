#pragma once

#include <arrow/api.h>
#include <arrow/io/api.h>
#include <arrow/util/byte_size.h>
#include <parquet/arrow/writer.h>

#include "Record.hpp"

namespace siac {
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
        ARROW_RETURN_NOT_OK(record.administrative_message_type.append(*administrative_message_type_builder));
        ARROW_RETURN_NOT_OK(record.message_indicator.append(*message_indicator_builder));
        ARROW_RETURN_NOT_OK(record.transaction_id.append(*transaction_id_builder));
        ARROW_RETURN_NOT_OK(record.participant_reference_number.append(*participant_reference_number_builder));
        ARROW_RETURN_NOT_OK(record.message_data_length.append(*message_data_length_builder));
        ARROW_RETURN_NOT_OK(record.control_message_type.append(*control_message_type_builder));
        ARROW_RETURN_NOT_OK(record.equity_and_index_last_sale_message_type.append(*equity_and_index_last_sale_message_type_builder));
        ARROW_RETURN_NOT_OK(record.security_symbol.append(*security_symbol_builder));
        ARROW_RETURN_NOT_OK(record.reserved_1.append(*reserved_1_builder));
        ARROW_RETURN_NOT_OK(record.expiration_month.append(*expiration_month_builder));
        ARROW_RETURN_NOT_OK(record.expiration_day.append(*expiration_day_builder));
        ARROW_RETURN_NOT_OK(record.expiration_year.append(*expiration_year_builder));
        ARROW_RETURN_NOT_OK(record.strike_price_denominator_code.append(*strike_price_denominator_code_builder));
        ARROW_RETURN_NOT_OK(record.strike_price.append(*strike_price_builder));
        ARROW_RETURN_NOT_OK(record.volume.append(*volume_builder));
        ARROW_RETURN_NOT_OK(record.premium_price_denominator_code.append(*premium_price_denominator_code_builder));
        ARROW_RETURN_NOT_OK(record.premium_price.append(*premium_price_builder));
        ARROW_RETURN_NOT_OK(record.trade_identifier.append(*trade_identifier_builder));
        ARROW_RETURN_NOT_OK(record.reserved_4.append(*reserved_4_builder));
        ARROW_RETURN_NOT_OK(record.open_interest_message_type.append(*open_interest_message_type_builder));
        ARROW_RETURN_NOT_OK(record.open_interest_volume.append(*open_interest_volume_builder));
        ARROW_RETURN_NOT_OK(record.equity_and_index_end_of_day_summary_message_type.append(*equity_and_index_end_of_day_summary_message_type_builder));
        ARROW_RETURN_NOT_OK(record.open_price.append(*open_price_builder));
        ARROW_RETURN_NOT_OK(record.high_price.append(*high_price_builder));
        ARROW_RETURN_NOT_OK(record.low_price.append(*low_price_builder));
        ARROW_RETURN_NOT_OK(record.last_price.append(*last_price_builder));
        ARROW_RETURN_NOT_OK(record.net_change.append(*net_change_builder));
        ARROW_RETURN_NOT_OK(record.underlying_price_denominator_code.append(*underlying_price_denominator_code_builder));
        ARROW_RETURN_NOT_OK(record.underlying_price.append(*underlying_price_builder));
        ARROW_RETURN_NOT_OK(record.bid_price.append(*bid_price_builder));
        ARROW_RETURN_NOT_OK(record.offer_price.append(*offer_price_builder));
        ARROW_RETURN_NOT_OK(record.long_equity_and_index_quote_message_type.append(*long_equity_and_index_quote_message_type_builder));
        ARROW_RETURN_NOT_OK(record.bbo_indicator.append(*bbo_indicator_builder));
        ARROW_RETURN_NOT_OK(record.bid_size.append(*bid_size_builder));
        ARROW_RETURN_NOT_OK(record.offer_size.append(*offer_size_builder));
        ARROW_RETURN_NOT_OK(record.short_equity_and_index_quote_message_type.append(*short_equity_and_index_quote_message_type_builder));
        ARROW_RETURN_NOT_OK(record.security_symbol_short.append(*security_symbol_short_builder));
        ARROW_RETURN_NOT_OK(record.strike_price_short.append(*strike_price_short_builder));
        ARROW_RETURN_NOT_OK(record.bid_price_short.append(*bid_price_short_builder));
        ARROW_RETURN_NOT_OK(record.bid_size_short.append(*bid_size_short_builder));
        ARROW_RETURN_NOT_OK(record.offer_price_short.append(*offer_price_short_builder));
        ARROW_RETURN_NOT_OK(record.offer_size_short.append(*offer_size_short_builder));
        ARROW_RETURN_NOT_OK(record.underlying_value_message_type.append(*underlying_value_message_type_builder));
        ARROW_RETURN_NOT_OK(record.index_value_denominator_code.append(*index_value_denominator_code_builder));
        ARROW_RETURN_NOT_OK(record.index_value.append(*index_value_builder));
        ARROW_RETURN_NOT_OK(record.bid_index_value.append(*bid_index_value_builder));
        ARROW_RETURN_NOT_OK(record.offer_index_value.append(*offer_index_value_builder));
        ARROW_RETURN_NOT_OK(record.best_bid_participant_id.append(*best_bid_participant_id_builder));
        ARROW_RETURN_NOT_OK(record.best_bid_denominator_code.append(*best_bid_denominator_code_builder));
        ARROW_RETURN_NOT_OK(record.best_bid_price.append(*best_bid_price_builder));
        ARROW_RETURN_NOT_OK(record.best_bid_size.append(*best_bid_size_builder));
        ARROW_RETURN_NOT_OK(record.best_offer_participant_id.append(*best_offer_participant_id_builder));
        ARROW_RETURN_NOT_OK(record.best_offer_denominator_code.append(*best_offer_denominator_code_builder));
        ARROW_RETURN_NOT_OK(record.best_offer_price.append(*best_offer_price_builder));
        ARROW_RETURN_NOT_OK(record.best_offer_size.append(*best_offer_size_builder));

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
        std::shared_ptr<arrow::Array> administrative_message_type_column;
        std::shared_ptr<arrow::Array> message_indicator_column;
        std::shared_ptr<arrow::Array> transaction_id_column;
        std::shared_ptr<arrow::Array> participant_reference_number_column;
        std::shared_ptr<arrow::Array> message_data_length_column;
        std::shared_ptr<arrow::Array> control_message_type_column;
        std::shared_ptr<arrow::Array> equity_and_index_last_sale_message_type_column;
        std::shared_ptr<arrow::Array> security_symbol_column;
        std::shared_ptr<arrow::Array> reserved_1_column;
        std::shared_ptr<arrow::Array> expiration_month_column;
        std::shared_ptr<arrow::Array> expiration_day_column;
        std::shared_ptr<arrow::Array> expiration_year_column;
        std::shared_ptr<arrow::Array> strike_price_denominator_code_column;
        std::shared_ptr<arrow::Array> strike_price_column;
        std::shared_ptr<arrow::Array> volume_column;
        std::shared_ptr<arrow::Array> premium_price_denominator_code_column;
        std::shared_ptr<arrow::Array> premium_price_column;
        std::shared_ptr<arrow::Array> trade_identifier_column;
        std::shared_ptr<arrow::Array> reserved_4_column;
        std::shared_ptr<arrow::Array> open_interest_message_type_column;
        std::shared_ptr<arrow::Array> open_interest_volume_column;
        std::shared_ptr<arrow::Array> equity_and_index_end_of_day_summary_message_type_column;
        std::shared_ptr<arrow::Array> open_price_column;
        std::shared_ptr<arrow::Array> high_price_column;
        std::shared_ptr<arrow::Array> low_price_column;
        std::shared_ptr<arrow::Array> last_price_column;
        std::shared_ptr<arrow::Array> net_change_column;
        std::shared_ptr<arrow::Array> underlying_price_denominator_code_column;
        std::shared_ptr<arrow::Array> underlying_price_column;
        std::shared_ptr<arrow::Array> bid_price_column;
        std::shared_ptr<arrow::Array> offer_price_column;
        std::shared_ptr<arrow::Array> long_equity_and_index_quote_message_type_column;
        std::shared_ptr<arrow::Array> bbo_indicator_column;
        std::shared_ptr<arrow::Array> bid_size_column;
        std::shared_ptr<arrow::Array> offer_size_column;
        std::shared_ptr<arrow::Array> short_equity_and_index_quote_message_type_column;
        std::shared_ptr<arrow::Array> security_symbol_short_column;
        std::shared_ptr<arrow::Array> strike_price_short_column;
        std::shared_ptr<arrow::Array> bid_price_short_column;
        std::shared_ptr<arrow::Array> bid_size_short_column;
        std::shared_ptr<arrow::Array> offer_price_short_column;
        std::shared_ptr<arrow::Array> offer_size_short_column;
        std::shared_ptr<arrow::Array> underlying_value_message_type_column;
        std::shared_ptr<arrow::Array> index_value_denominator_code_column;
        std::shared_ptr<arrow::Array> index_value_column;
        std::shared_ptr<arrow::Array> bid_index_value_column;
        std::shared_ptr<arrow::Array> offer_index_value_column;
        std::shared_ptr<arrow::Array> best_bid_participant_id_column;
        std::shared_ptr<arrow::Array> best_bid_denominator_code_column;
        std::shared_ptr<arrow::Array> best_bid_price_column;
        std::shared_ptr<arrow::Array> best_bid_size_column;
        std::shared_ptr<arrow::Array> best_offer_participant_id_column;
        std::shared_ptr<arrow::Array> best_offer_denominator_code_column;
        std::shared_ptr<arrow::Array> best_offer_price_column;
        std::shared_ptr<arrow::Array> best_offer_size_column;

        ARROW_RETURN_NOT_OK(event_type_builder->Finish(&event_type_column));
        ARROW_RETURN_NOT_OK(administrative_message_type_builder->Finish(&administrative_message_type_column));
        ARROW_RETURN_NOT_OK(message_indicator_builder->Finish(&message_indicator_column));
        ARROW_RETURN_NOT_OK(transaction_id_builder->Finish(&transaction_id_column));
        ARROW_RETURN_NOT_OK(participant_reference_number_builder->Finish(&participant_reference_number_column));
        ARROW_RETURN_NOT_OK(message_data_length_builder->Finish(&message_data_length_column));
        ARROW_RETURN_NOT_OK(control_message_type_builder->Finish(&control_message_type_column));
        ARROW_RETURN_NOT_OK(equity_and_index_last_sale_message_type_builder->Finish(&equity_and_index_last_sale_message_type_column));
        ARROW_RETURN_NOT_OK(security_symbol_builder->Finish(&security_symbol_column));
        ARROW_RETURN_NOT_OK(reserved_1_builder->Finish(&reserved_1_column));
        ARROW_RETURN_NOT_OK(expiration_month_builder->Finish(&expiration_month_column));
        ARROW_RETURN_NOT_OK(expiration_day_builder->Finish(&expiration_day_column));
        ARROW_RETURN_NOT_OK(expiration_year_builder->Finish(&expiration_year_column));
        ARROW_RETURN_NOT_OK(strike_price_denominator_code_builder->Finish(&strike_price_denominator_code_column));
        ARROW_RETURN_NOT_OK(strike_price_builder->Finish(&strike_price_column));
        ARROW_RETURN_NOT_OK(volume_builder->Finish(&volume_column));
        ARROW_RETURN_NOT_OK(premium_price_denominator_code_builder->Finish(&premium_price_denominator_code_column));
        ARROW_RETURN_NOT_OK(premium_price_builder->Finish(&premium_price_column));
        ARROW_RETURN_NOT_OK(trade_identifier_builder->Finish(&trade_identifier_column));
        ARROW_RETURN_NOT_OK(reserved_4_builder->Finish(&reserved_4_column));
        ARROW_RETURN_NOT_OK(open_interest_message_type_builder->Finish(&open_interest_message_type_column));
        ARROW_RETURN_NOT_OK(open_interest_volume_builder->Finish(&open_interest_volume_column));
        ARROW_RETURN_NOT_OK(equity_and_index_end_of_day_summary_message_type_builder->Finish(&equity_and_index_end_of_day_summary_message_type_column));
        ARROW_RETURN_NOT_OK(open_price_builder->Finish(&open_price_column));
        ARROW_RETURN_NOT_OK(high_price_builder->Finish(&high_price_column));
        ARROW_RETURN_NOT_OK(low_price_builder->Finish(&low_price_column));
        ARROW_RETURN_NOT_OK(last_price_builder->Finish(&last_price_column));
        ARROW_RETURN_NOT_OK(net_change_builder->Finish(&net_change_column));
        ARROW_RETURN_NOT_OK(underlying_price_denominator_code_builder->Finish(&underlying_price_denominator_code_column));
        ARROW_RETURN_NOT_OK(underlying_price_builder->Finish(&underlying_price_column));
        ARROW_RETURN_NOT_OK(bid_price_builder->Finish(&bid_price_column));
        ARROW_RETURN_NOT_OK(offer_price_builder->Finish(&offer_price_column));
        ARROW_RETURN_NOT_OK(long_equity_and_index_quote_message_type_builder->Finish(&long_equity_and_index_quote_message_type_column));
        ARROW_RETURN_NOT_OK(bbo_indicator_builder->Finish(&bbo_indicator_column));
        ARROW_RETURN_NOT_OK(bid_size_builder->Finish(&bid_size_column));
        ARROW_RETURN_NOT_OK(offer_size_builder->Finish(&offer_size_column));
        ARROW_RETURN_NOT_OK(short_equity_and_index_quote_message_type_builder->Finish(&short_equity_and_index_quote_message_type_column));
        ARROW_RETURN_NOT_OK(security_symbol_short_builder->Finish(&security_symbol_short_column));
        ARROW_RETURN_NOT_OK(strike_price_short_builder->Finish(&strike_price_short_column));
        ARROW_RETURN_NOT_OK(bid_price_short_builder->Finish(&bid_price_short_column));
        ARROW_RETURN_NOT_OK(bid_size_short_builder->Finish(&bid_size_short_column));
        ARROW_RETURN_NOT_OK(offer_price_short_builder->Finish(&offer_price_short_column));
        ARROW_RETURN_NOT_OK(offer_size_short_builder->Finish(&offer_size_short_column));
        ARROW_RETURN_NOT_OK(underlying_value_message_type_builder->Finish(&underlying_value_message_type_column));
        ARROW_RETURN_NOT_OK(index_value_denominator_code_builder->Finish(&index_value_denominator_code_column));
        ARROW_RETURN_NOT_OK(index_value_builder->Finish(&index_value_column));
        ARROW_RETURN_NOT_OK(bid_index_value_builder->Finish(&bid_index_value_column));
        ARROW_RETURN_NOT_OK(offer_index_value_builder->Finish(&offer_index_value_column));
        ARROW_RETURN_NOT_OK(best_bid_participant_id_builder->Finish(&best_bid_participant_id_column));
        ARROW_RETURN_NOT_OK(best_bid_denominator_code_builder->Finish(&best_bid_denominator_code_column));
        ARROW_RETURN_NOT_OK(best_bid_price_builder->Finish(&best_bid_price_column));
        ARROW_RETURN_NOT_OK(best_bid_size_builder->Finish(&best_bid_size_column));
        ARROW_RETURN_NOT_OK(best_offer_participant_id_builder->Finish(&best_offer_participant_id_column));
        ARROW_RETURN_NOT_OK(best_offer_denominator_code_builder->Finish(&best_offer_denominator_code_column));
        ARROW_RETURN_NOT_OK(best_offer_price_builder->Finish(&best_offer_price_column));
        ARROW_RETURN_NOT_OK(best_offer_size_builder->Finish(&best_offer_size_column));

        auto batch = arrow::RecordBatch::Make(schema, row_count, {
            event_type_column,
            administrative_message_type_column,
            message_indicator_column,
            transaction_id_column,
            participant_reference_number_column,
            message_data_length_column,
            control_message_type_column,
            equity_and_index_last_sale_message_type_column,
            security_symbol_column,
            reserved_1_column,
            expiration_month_column,
            expiration_day_column,
            expiration_year_column,
            strike_price_denominator_code_column,
            strike_price_column,
            volume_column,
            premium_price_denominator_code_column,
            premium_price_column,
            trade_identifier_column,
            reserved_4_column,
            open_interest_message_type_column,
            open_interest_volume_column,
            equity_and_index_end_of_day_summary_message_type_column,
            open_price_column,
            high_price_column,
            low_price_column,
            last_price_column,
            net_change_column,
            underlying_price_denominator_code_column,
            underlying_price_column,
            bid_price_column,
            offer_price_column,
            long_equity_and_index_quote_message_type_column,
            bbo_indicator_column,
            bid_size_column,
            offer_size_column,
            short_equity_and_index_quote_message_type_column,
            security_symbol_short_column,
            strike_price_short_column,
            bid_price_short_column,
            bid_size_short_column,
            offer_price_short_column,
            offer_size_short_column,
            underlying_value_message_type_column,
            index_value_denominator_code_column,
            index_value_column,
            bid_index_value_column,
            offer_index_value_column,
            best_bid_participant_id_column,
            best_bid_denominator_code_column,
            best_bid_price_column,
            best_bid_size_column,
            best_offer_participant_id_column,
            best_offer_denominator_code_column,
            best_offer_price_column,
            best_offer_size_column,
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
        administrative_message_type_builder = std::make_unique<arrow::StringBuilder>();
        message_indicator_builder = std::make_unique<arrow::StringBuilder>();
        transaction_id_builder = std::make_unique<arrow::UInt32Builder>();
        participant_reference_number_builder = std::make_unique<arrow::UInt32Builder>();
        message_data_length_builder = std::make_unique<arrow::UInt16Builder>();
        control_message_type_builder = std::make_unique<arrow::StringBuilder>();
        equity_and_index_last_sale_message_type_builder = std::make_unique<arrow::StringBuilder>();
        security_symbol_builder = std::make_unique<arrow::StringBuilder>();
        reserved_1_builder = std::make_unique<arrow::UInt8Builder>();
        expiration_month_builder = std::make_unique<arrow::StringBuilder>();
        expiration_day_builder = std::make_unique<arrow::UInt8Builder>();
        expiration_year_builder = std::make_unique<arrow::UInt8Builder>();
        strike_price_denominator_code_builder = std::make_unique<arrow::StringBuilder>();
        strike_price_builder = std::make_unique<arrow::UInt32Builder>();
        volume_builder = std::make_unique<arrow::UInt32Builder>();
        premium_price_denominator_code_builder = std::make_unique<arrow::StringBuilder>();
        premium_price_builder = std::make_unique<arrow::Int32Builder>();
        trade_identifier_builder = std::make_unique<arrow::UInt32Builder>();
        reserved_4_builder = std::make_unique<arrow::UInt32Builder>();
        open_interest_message_type_builder = std::make_unique<arrow::StringBuilder>();
        open_interest_volume_builder = std::make_unique<arrow::UInt32Builder>();
        equity_and_index_end_of_day_summary_message_type_builder = std::make_unique<arrow::StringBuilder>();
        open_price_builder = std::make_unique<arrow::Int32Builder>();
        high_price_builder = std::make_unique<arrow::Int32Builder>();
        low_price_builder = std::make_unique<arrow::Int32Builder>();
        last_price_builder = std::make_unique<arrow::Int32Builder>();
        net_change_builder = std::make_unique<arrow::Int32Builder>();
        underlying_price_denominator_code_builder = std::make_unique<arrow::StringBuilder>();
        underlying_price_builder = std::make_unique<arrow::Int64Builder>();
        bid_price_builder = std::make_unique<arrow::Int32Builder>();
        offer_price_builder = std::make_unique<arrow::Int32Builder>();
        long_equity_and_index_quote_message_type_builder = std::make_unique<arrow::StringBuilder>();
        bbo_indicator_builder = std::make_unique<arrow::StringBuilder>();
        bid_size_builder = std::make_unique<arrow::UInt32Builder>();
        offer_size_builder = std::make_unique<arrow::UInt32Builder>();
        short_equity_and_index_quote_message_type_builder = std::make_unique<arrow::StringBuilder>();
        security_symbol_short_builder = std::make_unique<arrow::StringBuilder>();
        strike_price_short_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(StrikePriceShort::precision, StrikePriceShort::scale));
        bid_price_short_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(BidPriceShort::precision, BidPriceShort::scale));
        bid_size_short_builder = std::make_unique<arrow::UInt16Builder>();
        offer_price_short_builder = std::make_unique<arrow::Decimal128Builder>(arrow::decimal128(OfferPriceShort::precision, OfferPriceShort::scale));
        offer_size_short_builder = std::make_unique<arrow::UInt16Builder>();
        underlying_value_message_type_builder = std::make_unique<arrow::StringBuilder>();
        index_value_denominator_code_builder = std::make_unique<arrow::StringBuilder>();
        index_value_builder = std::make_unique<arrow::Int32Builder>();
        bid_index_value_builder = std::make_unique<arrow::Int32Builder>();
        offer_index_value_builder = std::make_unique<arrow::Int64Builder>();
        best_bid_participant_id_builder = std::make_unique<arrow::StringBuilder>();
        best_bid_denominator_code_builder = std::make_unique<arrow::StringBuilder>();
        best_bid_price_builder = std::make_unique<arrow::Int32Builder>();
        best_bid_size_builder = std::make_unique<arrow::UInt32Builder>();
        best_offer_participant_id_builder = std::make_unique<arrow::StringBuilder>();
        best_offer_denominator_code_builder = std::make_unique<arrow::StringBuilder>();
        best_offer_price_builder = std::make_unique<arrow::Int32Builder>();
        best_offer_size_builder = std::make_unique<arrow::UInt32Builder>();

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
        std::unique_ptr<arrow::StringBuilder> administrative_message_type_builder;
        std::unique_ptr<arrow::StringBuilder> message_indicator_builder;
        std::unique_ptr<arrow::UInt32Builder> transaction_id_builder;
        std::unique_ptr<arrow::UInt32Builder> participant_reference_number_builder;
        std::unique_ptr<arrow::UInt16Builder> message_data_length_builder;
        std::unique_ptr<arrow::StringBuilder> control_message_type_builder;
        std::unique_ptr<arrow::StringBuilder> equity_and_index_last_sale_message_type_builder;
        std::unique_ptr<arrow::StringBuilder> security_symbol_builder;
        std::unique_ptr<arrow::UInt8Builder> reserved_1_builder;
        std::unique_ptr<arrow::StringBuilder> expiration_month_builder;
        std::unique_ptr<arrow::UInt8Builder> expiration_day_builder;
        std::unique_ptr<arrow::UInt8Builder> expiration_year_builder;
        std::unique_ptr<arrow::StringBuilder> strike_price_denominator_code_builder;
        std::unique_ptr<arrow::UInt32Builder> strike_price_builder;
        std::unique_ptr<arrow::UInt32Builder> volume_builder;
        std::unique_ptr<arrow::StringBuilder> premium_price_denominator_code_builder;
        std::unique_ptr<arrow::Int32Builder> premium_price_builder;
        std::unique_ptr<arrow::UInt32Builder> trade_identifier_builder;
        std::unique_ptr<arrow::UInt32Builder> reserved_4_builder;
        std::unique_ptr<arrow::StringBuilder> open_interest_message_type_builder;
        std::unique_ptr<arrow::UInt32Builder> open_interest_volume_builder;
        std::unique_ptr<arrow::StringBuilder> equity_and_index_end_of_day_summary_message_type_builder;
        std::unique_ptr<arrow::Int32Builder> open_price_builder;
        std::unique_ptr<arrow::Int32Builder> high_price_builder;
        std::unique_ptr<arrow::Int32Builder> low_price_builder;
        std::unique_ptr<arrow::Int32Builder> last_price_builder;
        std::unique_ptr<arrow::Int32Builder> net_change_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_price_denominator_code_builder;
        std::unique_ptr<arrow::Int64Builder> underlying_price_builder;
        std::unique_ptr<arrow::Int32Builder> bid_price_builder;
        std::unique_ptr<arrow::Int32Builder> offer_price_builder;
        std::unique_ptr<arrow::StringBuilder> long_equity_and_index_quote_message_type_builder;
        std::unique_ptr<arrow::StringBuilder> bbo_indicator_builder;
        std::unique_ptr<arrow::UInt32Builder> bid_size_builder;
        std::unique_ptr<arrow::UInt32Builder> offer_size_builder;
        std::unique_ptr<arrow::StringBuilder> short_equity_and_index_quote_message_type_builder;
        std::unique_ptr<arrow::StringBuilder> security_symbol_short_builder;
        std::unique_ptr<arrow::Decimal128Builder> strike_price_short_builder;
        std::unique_ptr<arrow::Decimal128Builder> bid_price_short_builder;
        std::unique_ptr<arrow::UInt16Builder> bid_size_short_builder;
        std::unique_ptr<arrow::Decimal128Builder> offer_price_short_builder;
        std::unique_ptr<arrow::UInt16Builder> offer_size_short_builder;
        std::unique_ptr<arrow::StringBuilder> underlying_value_message_type_builder;
        std::unique_ptr<arrow::StringBuilder> index_value_denominator_code_builder;
        std::unique_ptr<arrow::Int32Builder> index_value_builder;
        std::unique_ptr<arrow::Int32Builder> bid_index_value_builder;
        std::unique_ptr<arrow::Int64Builder> offer_index_value_builder;
        std::unique_ptr<arrow::StringBuilder> best_bid_participant_id_builder;
        std::unique_ptr<arrow::StringBuilder> best_bid_denominator_code_builder;
        std::unique_ptr<arrow::Int32Builder> best_bid_price_builder;
        std::unique_ptr<arrow::UInt32Builder> best_bid_size_builder;
        std::unique_ptr<arrow::StringBuilder> best_offer_participant_id_builder;
        std::unique_ptr<arrow::StringBuilder> best_offer_denominator_code_builder;
        std::unique_ptr<arrow::Int32Builder> best_offer_price_builder;
        std::unique_ptr<arrow::UInt32Builder> best_offer_size_builder;
};
}
