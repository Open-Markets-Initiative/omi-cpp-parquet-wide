#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// Identifies the channel
struct ChannelId {

    static constexpr const char* name = "Channel Id";
    static constexpr std::size_t size =  2;
    using type = std::uint16_t;

    // default constructor
    constexpr ChannelId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ChannelId(const std::uint16_t value)
     : value{ value } {}

    // get value of ChannelId field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
