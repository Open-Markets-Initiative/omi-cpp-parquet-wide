#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// referencePriceOriginInTradingInterruption
struct ReferencePriceOriginInTradingInterruption {

    static constexpr const char* name = "Reference Price Origin In Trading Interruption";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr ReferencePriceOriginInTradingInterruption()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ReferencePriceOriginInTradingInterruption(const std::uint8_t value)
     : value{ value } {}

    // get value of ReferencePriceOriginInTradingInterruption field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
