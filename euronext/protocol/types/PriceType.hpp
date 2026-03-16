#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// priceType
struct PriceType {

    static constexpr const char* name = "Price Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr PriceType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PriceType(const std::uint8_t value)
     : value{ value } {}

    // get value of PriceType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
