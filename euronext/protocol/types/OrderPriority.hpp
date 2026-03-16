#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// orderPriority
struct OrderPriority {

    static constexpr const char* name = "Order Priority";
    static constexpr std::size_t size =  8;
static const std::uint64_t no_value = 18446744073709551615;

    // default constructor
    constexpr OrderPriority()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OrderPriority(const std::uint64_t value)
     : value{ value } {}

    // get value of OrderPriority field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
