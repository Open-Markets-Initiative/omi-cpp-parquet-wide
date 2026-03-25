#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// collarUnhaltDelay
struct CollarUnhaltDelay {

    static constexpr const char* name = "Collar Unhalt Delay";
    static constexpr std::size_t size =  4;
    using type = std::uint32_t;
static const type no_value = 4294967295;

    // default constructor
    constexpr CollarUnhaltDelay()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit CollarUnhaltDelay(const std::uint32_t value)
     : value{ value } {}

    // get value of CollarUnhaltDelay field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
