#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// orderSide
struct OrderSide {

    static constexpr const char* name = "Order Side";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr OrderSide()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OrderSide(const std::uint8_t value)
     : value{ value } {}

    // get value of OrderSide field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
