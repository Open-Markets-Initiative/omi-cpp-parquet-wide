#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// maximumDecimalsInQuantity
struct MaximumDecimalsInQuantity {

    static constexpr const char* name = "Maximum Decimals In Quantity";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr MaximumDecimalsInQuantity()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MaximumDecimalsInQuantity(const std::uint8_t value)
     : value{ value } {}

    // get value of MaximumDecimalsInQuantity field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
