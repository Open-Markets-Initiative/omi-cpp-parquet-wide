#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// dynamicCollarLogic
struct DynamicCollarLogic {

    static constexpr const char* name = "Dynamic Collar Logic";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr DynamicCollarLogic()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DynamicCollarLogic(const std::uint8_t value)
     : value{ value } {}

    // get value of DynamicCollarLogic field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
