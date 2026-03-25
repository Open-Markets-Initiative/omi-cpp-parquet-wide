#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// priceMultiplierDecimals
struct PriceMultiplierDecimals {

    static constexpr const char* name = "Price Multiplier Decimals";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr PriceMultiplierDecimals()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PriceMultiplierDecimals(const std::uint8_t value)
     : value{ value } {}

    // get value of PriceMultiplierDecimals field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
