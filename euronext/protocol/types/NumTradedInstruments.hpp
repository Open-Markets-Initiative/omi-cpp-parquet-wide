#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// numTradedInstruments
struct NumTradedInstruments {

    static constexpr const char* name = "Num Traded Instruments";
    static constexpr std::size_t size =  2;
static const std::uint16_t no_value = 65535;

    // default constructor
    constexpr NumTradedInstruments()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit NumTradedInstruments(const std::uint16_t value)
     : value{ value } {}

    // get value of NumTradedInstruments field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
