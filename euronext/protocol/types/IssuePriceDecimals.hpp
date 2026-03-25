#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// issuePriceDecimals
struct IssuePriceDecimals {

    static constexpr const char* name = "Issue Price Decimals";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr IssuePriceDecimals()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit IssuePriceDecimals(const std::uint8_t value)
     : value{ value } {}

    // get value of IssuePriceDecimals field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
