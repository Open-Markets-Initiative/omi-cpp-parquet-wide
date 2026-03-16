#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// darkEligibility
struct DarkEligibility {

    static constexpr const char* name = "Dark Eligibility";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr DarkEligibility()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DarkEligibility(const std::uint8_t value)
     : value{ value } {}

    // get value of DarkEligibility field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
