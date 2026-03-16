#pragma once

#include "../types/PacketTime.hpp"
#include "../types/PacketSequenceNumber.hpp"
#include "../bitfields/PacketFlags.hpp"
#include "../types/ChannelId.hpp"

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

#pragma pack(push, 1)

struct MarketDataPacketHeader {

    PacketTime packet_time;
    PacketSequenceNumber packet_sequence_number;
    PacketFlags packet_flags;
    ChannelId channel_id;

    // parse method
    static MarketDataPacketHeader* parse(std::byte* buffer) {
        return reinterpret_cast<MarketDataPacketHeader*>(buffer);
    }

    // parse method const
    static const MarketDataPacketHeader* parse(const std::byte* buffer) {
        return reinterpret_cast<const MarketDataPacketHeader*>(buffer);
    }
};

#pragma pack(pop)
}
