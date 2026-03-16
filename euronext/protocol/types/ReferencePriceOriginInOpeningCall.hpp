#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// referencePriceOriginInOpeningCall
struct ReferencePriceOriginInOpeningCall {

    static constexpr const char* name = "Reference Price Origin In Opening Call";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr ReferencePriceOriginInOpeningCall()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ReferencePriceOriginInOpeningCall(const std::uint8_t value)
     : value{ value } {}

    // get value of ReferencePriceOriginInOpeningCall field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
