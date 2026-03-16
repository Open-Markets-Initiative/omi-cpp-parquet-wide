#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// dateOfLastTrade
struct DateOfLastTrade {

    static constexpr const char* name = "Date Of Last Trade";
    static constexpr std::size_t size =  2;
static const std::uint16_t no_value = 65535;

    // default constructor
    constexpr DateOfLastTrade()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DateOfLastTrade(const std::uint16_t value)
     : value{ value } {}

    // get value of DateOfLastTrade field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
