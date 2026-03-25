#pragma once

#include "../definitions.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {
// OptiqMessageIterator
struct OptiqMessageIterator {

    const std::byte* current = nullptr;
    const std::byte* end = nullptr;

    const MarketDataPacketHeader* market_data_packet_header = nullptr;

    std::uint16_t template_id = 0;
    std::uint16_t frame = 0;
    const std::byte* message = nullptr;

    // initialize parser
    void initialize(const std::byte* data, std::size_t length) {

        end = data + length;

        if (length < sizeof(MarketDataPacketHeader)) {
            current = end;
            message = nullptr;
            market_data_packet_header = nullptr;
            template_id = 0;
            frame = 0;
            return;
        }

        market_data_packet_header = MarketDataPacketHeader::parse(data);
        current = data + sizeof(MarketDataPacketHeader);
        message = nullptr;

        template_id = 0;
        frame = 0;
    }

    // next message
    bool next() {

        if (current >= end) {
            return false;
        }

        if (current + sizeof(OptiqMessage) > end) {
            return false;
        }

        const auto* header = OptiqMessage::parse(current);
        message = current + sizeof(OptiqMessage);

        template_id = header->message_header.template_id.get();
        frame = header->frame.get();

        current += frame;

        return true;
    }

    // reset iterator
    void reset() {
        current = nullptr;
        end = nullptr;

        market_data_packet_header = nullptr;
        message = nullptr;
        template_id = 0;
        frame = 0;
    }
};
}
