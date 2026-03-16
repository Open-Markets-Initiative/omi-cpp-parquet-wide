#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// derivativesInstrumentType
struct DerivativesInstrumentType {

    static constexpr const char* name = "Derivatives Instrument Type";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr DerivativesInstrumentType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DerivativesInstrumentType(const std::uint8_t value)
     : value{ value } {}

    // get value of DerivativesInstrumentType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
