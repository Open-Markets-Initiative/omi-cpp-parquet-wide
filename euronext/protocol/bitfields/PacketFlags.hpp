#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// Packet Flags
struct PacketFlags {

    // underlying type
    using type = std::uint16_t;

    static constexpr const char* name = "Packet Flags";
    static constexpr std::size_t size = 2;

    struct mask {
        static const type Compression = 0x0001;
        static const type MdgRestartCount = 0x000E;
        static const type PsnHighWeight = 0x0070;
        static const type HasStartOfDaySnapshot = 0x0080;
        static const type HasEndOfDaySnapshot = 0x0100;
        static const type HasStatusMessage = 0x0200;
    };

    // default constructor
    constexpr PacketFlags()
     : value{ 0 } {}

    // body of the packet is compressed
    [[nodiscard]] constexpr bool Compression() const {
        return value & mask::Compression;
    }

    // Will be set to 0 every morning and incremented for each restart of MDG in the same day
    [[nodiscard]] constexpr bool MdgRestartCount() const {
        return value & mask::MdgRestartCount;
    }

    // Packet Sequence Number goes over (2^32)-1. They are PSN high weight bits
    [[nodiscard]] constexpr bool PsnHighWeight() const {
        return value & mask::PsnHighWeight;
    }

    // Packet contains Start Of Day Snapshot
    [[nodiscard]] constexpr bool HasStartOfDaySnapshot() const {
        return value & mask::HasStartOfDaySnapshot;
    }

    // Packet contains End Of Day Snapshot
    [[nodiscard]] constexpr bool HasEndOfDaySnapshot() const {
        return value & mask::HasEndOfDaySnapshot;
    }

    // Packet contains a Health Status (1103) message, Start Of Day (1101) message or End Of Day (1102) message
    [[nodiscard]] constexpr bool HasStatusMessage() const {
        return value & mask::HasStatusMessage;
    }

  protected:
    type value;
};
}
