#pragma once

#include "Settings.hpp"

#include "../packet/Parser.hpp"
#include "../parquet/Writer.hpp"
#include "../conversion/Manager.hpp"

namespace program {

// todo
struct Runner {

    packet::Parser parser;
    euronext::Writer writer;
    euronext::optiq::marketdatagateway::sbe::v5_25::Manager euronext;

    const program::Options& options;

    explicit Runner(const program::Options& options)
     : options{ options }, parser{ options.pcap }, writer{ options.parquet }, euronext{ options.conversion, parser, writer } {}

    void run() {

        while (parser.next()) {
            const auto type = parser.identify();

            switch (type) {
                case packet::result::euronext_optiq_marketdatagateway_sbe_v5_25:
                    euronext.udp();
                    break;
                default:
                    break;
            }
        }
    }
};
}
