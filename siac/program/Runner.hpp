#pragma once

#include "Settings.hpp"

#include "../packet/Parser.hpp"
#include "../parquet/Writer.hpp"
#include "../conversion/Manager.hpp"

namespace program {

// todo
struct Runner {

    packet::Parser parser;
    siac::Writer writer;
    siac::opra::recipient::obi::v6_2::Manager siac;

    const program::Options& options;

    explicit Runner(const program::Options& options)
     : options{ options }, parser{ options.pcap }, writer{ options.parquet }, siac{ options.conversion, parser, writer } {}

    void run() {

        while (parser.next()) {
            const auto type = parser.identify();

            switch (type) {
                case packet::result::siac_opra_recipient_obi_v6_2:
                    siac.udp();
                    break;
                default:
                    break;
            }
        }
    }
};
}
