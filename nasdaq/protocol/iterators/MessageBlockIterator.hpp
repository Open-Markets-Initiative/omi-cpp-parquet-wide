#pragma once

#include "../definitions.hpp"

namespace nasdaq::nsmequities::totalview::itch::v5_0 {
// MessageBlockIterator
struct MessageBlockIterator {

    const std::byte* current = nullptr;

    const PacketHeader* packet_header = nullptr;
    const MessageHeader* message_header = nullptr;

    std::uint16_t message_count = 0;
    std::uint16_t message_index = 0;
    char message_type = 0;
    std::uint16_t message_length = 0;
    const std::byte* message = nullptr;

    // initialize parser
    void initialize(const std::byte* data) {

        current = data;
        message = nullptr;

        packet_header = PacketHeader::parse(current);
        current += sizeof(PacketHeader);

        message_header = nullptr;
        message_index = 0;
        message_type = 0;
        message_length = 0;
        message_count = packet_header->message_count.get();
    }

    // next message
    bool next() {

        if (message_index >= message_count) {
            return false;
        }

        message_index++;

        message_header = MessageHeader::parse(current);
        message = current + sizeof(MessageHeader);

        message_type = message_header->message_type.get();
        message_length = message_header->message_length.get();

        current += message_length + 2;

        return true;
    }

    // reset iterator
    void reset() {
        current = nullptr;

        packet_header = nullptr;
        message_header = nullptr;

        message = nullptr;
        message_count = 0;
        message_index = 0;
        message_type = 0;
        message_length = 0;
    }
};
}
