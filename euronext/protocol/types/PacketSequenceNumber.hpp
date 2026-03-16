#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// Each channel has its own PSN sequence
struct PacketSequenceNumber {

    static constexpr const char* name = "Packet Sequence Number";
    static constexpr std::size_t size =  4;

    // default constructor
    constexpr PacketSequenceNumber()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PacketSequenceNumber(const std::uint32_t value)
     : value{ value } {}

    // get value of PacketSequenceNumber field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
