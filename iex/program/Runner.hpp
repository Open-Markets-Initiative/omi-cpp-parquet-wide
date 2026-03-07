#pragma once

#include "Settings.hpp"

#include "../packet/Parser.hpp"
#include "../parquet/Writer.hpp"
#include "../conversion/Manager.hpp"

namespace program {

// todo
struct Runner {

    packet::Parser parser;
    iex::Writer writer;
    iex::equities::tops::iextp::v1_6_6::Manager iex;

    const program::Options& options;

    explicit Runner(const program::Options& options)
     : options{ options }, parser{ options.pcap }, writer{ options.parquet }, iex{ options.conversion, parser, writer } {}

    void run() {

        while (parser.next()) {
            const auto type = parser.identify();

            switch (type) {
                case packet::result::iex_equities_tops_iextp_v1_6_6:
                    iex.udp();
                    break;
                default:
                    break;
            }
        }
    }
};
}
