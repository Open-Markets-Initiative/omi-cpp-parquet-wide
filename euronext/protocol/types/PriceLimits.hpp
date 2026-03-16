#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// priceLimits
struct PriceLimits {

    static constexpr const char* name = "Price Limits";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr PriceLimits()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PriceLimits(const std::uint8_t value)
     : value{ value } {}

    // get value of PriceLimits field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
