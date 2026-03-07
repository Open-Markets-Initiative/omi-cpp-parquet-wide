#pragma once

#include <iostream>

#include <boost/program_options.hpp>

#include "Settings.hpp"

namespace program {

program::Options args(const int argc, char** argv) {

    // define and describe options
    boost::program_options::options_description description("omi itch to parquet");
    description.add_options()
        ("help,h", "Show program help")
        ("input,i", boost::program_options::value<std::string>()->default_value("itch.pcap"), "Input pcap file")
        ("output,o", boost::program_options::value<std::string>()->default_value("itch.parquet"), "Output parquet file")
        ("exchange,e", boost::program_options::value<std::string>()->default_value("Nasdaq"), "Exchange field")
        ("row-group-size", boost::program_options::value<std::int64_t>()->default_value(1000), "Max rows per row group")
        ("compression", boost::program_options::value<std::string>()->default_value("zstd"), "Compression codec (zstd/snappy/gzip/lz4/brotli/none)")
        ("compression-level", boost::program_options::value<std::int32_t>()->default_value(3), "Compression level")
        ("dictionary", boost::program_options::value<bool>()->default_value(true), "Enable dictionary encoding")
        ("data-page-size", boost::program_options::value<std::int64_t>()->default_value(1048576), "Data page size in bytes")
        ("dictionary-page-size", boost::program_options::value<std::int64_t>()->default_value(1048576), "Dictionary page size in bytes")
        ("statistics", boost::program_options::value<bool>()->default_value(true), "Write column statistics")
        ("parquet-version", boost::program_options::value<std::string>()->default_value("2.6"), "Parquet format version")
        ("max-file-size", boost::program_options::value<std::int64_t>()->default_value(1073741824), "Max file size in bytes (0 = unlimited)")
        ("verbose,v", boost::program_options::value<bool>()->default_value(false), "Verbose output");

    // Parse command-line arguments
    auto parsed = boost::program_options::parse_command_line(argc, argv, description);
    boost::program_options::variables_map variables;
    boost::program_options::store(parsed, variables);
    boost::program_options::notify(variables);

    // check to display help
    if (variables.contains("help")) {
        std::cout << description << std::endl;
        exit(1);
    }

    // parse program options
    program::Options options;

    options.pcap.file = variables["input"].as<std::string>();
    options.conversion.exchange = variables["exchange"].as<std::string>();

    // parquet options
    options.parquet.file = variables["output"].as<std::string>();
    options.parquet.max_row_group_size = variables["row-group-size"].as<std::int64_t>();
    options.parquet.compression = variables["compression"].as<std::string>();
    options.parquet.compression_level = variables["compression-level"].as<std::int32_t>();
    options.parquet.dictionary_enabled = variables["dictionary"].as<bool>();
    options.parquet.data_page_size = variables["data-page-size"].as<std::int64_t>();
    options.parquet.dictionary_page_size = variables["dictionary-page-size"].as<std::int64_t>();
    options.parquet.write_statistics = variables["statistics"].as<bool>();
    options.parquet.version = variables["parquet-version"].as<std::string>();
    options.parquet.max_file_size = variables["max-file-size"].as<std::int64_t>();

    return options;
}

}