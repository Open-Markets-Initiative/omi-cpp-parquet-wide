#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// priceDecimals
struct PriceDecimalsOptional {

    static constexpr const char* name = "Price Decimals Optional";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr PriceDecimalsOptional()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PriceDecimalsOptional(const std::uint8_t value)
     : value{ value } {}

    // get value of PriceDecimalsOptional field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
