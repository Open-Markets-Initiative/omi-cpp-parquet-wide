#pragma once

#include <cstdint>
#include <string>

namespace parquet {

// parquet writer options
struct Options {
    std::string file = "itch.parquet";
    std::int64_t max_row_group_size = 1000;

    // compression
    std::string compression = "zstd";
    std::int32_t compression_level = 3;

    // encoding
    bool dictionary_enabled = true;

    // page sizes
    std::int64_t data_page_size = 1024 * 1024;
    std::int64_t dictionary_page_size = 1024 * 1024;

    // statistics
    bool write_statistics = true;

    // parquet format version
    std::string version = "2.6";

    // file splitting (0 = unlimited)
    std::int64_t max_file_size = 1024LL * 1024 * 1024;
};

}