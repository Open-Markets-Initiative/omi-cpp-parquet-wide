#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// orderQuantity
struct OrderQuantity {

    static constexpr const char* name = "Order Quantity";
    static constexpr std::size_t size =  8;
static const std::uint64_t no_value = 18446744073709551615;

    // default constructor
    constexpr OrderQuantity()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OrderQuantity(const std::uint64_t value)
     : value{ value } {}

    // get value of OrderQuantity field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
