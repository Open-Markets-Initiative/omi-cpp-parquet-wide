#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// priceDecimals
struct PriceDecimals {

    static constexpr const char* name = "Price Decimals";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr PriceDecimals()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PriceDecimals(const std::uint8_t value)
     : value{ value } {}

    // get value of PriceDecimals field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
