#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// numberOfOrders
struct NumberOfOrders {

    static constexpr const char* name = "Number Of Orders";
    static constexpr std::size_t size =  2;
static const std::uint16_t no_value = 65535;

    // default constructor
    constexpr NumberOfOrders()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit NumberOfOrders(const std::uint16_t value)
     : value{ value } {}

    // get value of NumberOfOrders field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
