#pragma once

#include "Settings.hpp"

#include "../packet/Parser.hpp"
#include "../parquet/Writer.hpp"
#include "../conversion/Manager.hpp"

namespace program {

// todo
struct Runner {

    packet::Parser parser;
    cme::Writer writer;
    cme::mdp3::v8::Manager cme;

    const program::Options& options;

    explicit Runner(const program::Options& options)
     : options{ options }, parser{ options.pcap }, writer{ options.parquet }, cme{ options.conversion, parser, writer } {}

    void run() {

        while (parser.next()) {
            const auto type = parser.identify();

            switch (type) {
                case packet::result::cme_futures_mdp3_sbe_v1_8:
                    cme.udp();
                    break;
                default:
                    break;
            }
        }
    }
};
}
