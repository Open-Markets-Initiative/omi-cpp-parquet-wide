#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// daysToExpiry
struct DaysToExpiry {

    static constexpr const char* name = "Days To Expiry";
    static constexpr std::size_t size =  2;
static const std::uint16_t no_value = 65535;

    // default constructor
    constexpr DaysToExpiry()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DaysToExpiry(const std::uint16_t value)
     : value{ value } {}

    // get value of DaysToExpiry field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
