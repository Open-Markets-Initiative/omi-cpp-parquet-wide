#pragma once

#include "../definitions.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {
// OptiqMessageIterator
struct OptiqMessageIterator {

    const std::byte* current = nullptr;
    const std::byte* end = nullptr;

    std::uint16_t template_id = 0;
    std::uint16_t frame = 0;
    const std::byte* message = nullptr;

    // initialize parser
    void initialize(const std::byte* data, std::size_t length) {

        current = data + sizeof(MarketDataPacketHeader);
        end = data + length;
        message = nullptr;

        template_id = 0;
        frame = 0;
    }

    // next message
    bool next() {

        if (current >= end) {
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

        message = nullptr;
        template_id = 0;
        frame = 0;
    }
};
}
