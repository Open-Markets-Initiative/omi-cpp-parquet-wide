#pragma once

#include "../types/Frame.hpp"
#include "../structs/MessageHeader.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct OptiqMessage {

    Frame frame;
    MessageHeader message_header;

    // parse method
    static OptiqMessage* parse(std::byte* buffer) {
        return reinterpret_cast<OptiqMessage*>(buffer);
    }

    // parse method const
    static const OptiqMessage* parse(const std::byte* buffer) {
        return reinterpret_cast<const OptiqMessage*>(buffer);
    }
};

#pragma pack(pop)
}
