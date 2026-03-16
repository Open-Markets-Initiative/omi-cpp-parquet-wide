#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// strikeCurrencyIndicator
struct StrikeCurrencyIndicator {

    static constexpr const char* name = "Strike Currency Indicator";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr StrikeCurrencyIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StrikeCurrencyIndicator(const std::uint8_t value)
     : value{ value } {}

    // get value of StrikeCurrencyIndicator field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
