#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// liquidInstrumentIndicator
struct LiquidInstrumentIndicator {

    static constexpr const char* name = "Liquid Instrument Indicator";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr LiquidInstrumentIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LiquidInstrumentIndicator(const std::uint8_t value)
     : value{ value } {}

    // get value of LiquidInstrumentIndicator field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
