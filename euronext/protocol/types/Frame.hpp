#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// Total bytes of packet including this header
struct Frame {

    static constexpr const char* name = "Frame";
    static constexpr std::size_t size =  2;

    // default constructor
    constexpr Frame()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Frame(const std::uint16_t value)
     : value{ value } {}

    // get value of Frame field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
