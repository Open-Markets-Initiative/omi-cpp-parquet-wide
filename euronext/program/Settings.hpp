#pragma once

#include "../packet/Settings.hpp"
#include "../parquet/Settings.hpp"
#include "../conversion/Settings.hpp"

namespace program {

// binary data to parquet options
struct Options {
    packet::Options pcap;
    parquet::Options parquet;
    conversion::Options conversion;
};

}