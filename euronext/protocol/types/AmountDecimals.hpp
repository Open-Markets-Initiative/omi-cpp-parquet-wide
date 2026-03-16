#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// amountDecimals
struct AmountDecimals {

    static constexpr const char* name = "Amount Decimals";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr AmountDecimals()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit AmountDecimals(const std::uint8_t value)
     : value{ value } {}

    // get value of AmountDecimals field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
