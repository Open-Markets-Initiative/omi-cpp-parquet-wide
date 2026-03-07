#pragma once

#include "Settings.hpp"

#include "../packet/Parser.hpp"
#include "../parquet/Writer.hpp"
#include "../conversion/Manager.hpp"

namespace program {

// todo
struct Runner {

    packet::Parser parser;
    nasdaq::Writer writer;
    nasdaq::nsmequities::totalview::itch::v5_0::Manager nasdaq;

    const program::Options& options;

    explicit Runner(const program::Options& options)
     : options{ options }, parser{ options.pcap }, writer{ options.parquet }, nasdaq{ options.conversion, parser, writer } {}

    void run() {

        while (parser.next()) {
            const auto type = parser.identify();

            switch (type) {
                case packet::result::nasdaq_nsmequities_totalview_itch_v5_0:
                    nasdaq.udp();
                    break;
                default:
                    break;
            }
        }
    }
};
}
