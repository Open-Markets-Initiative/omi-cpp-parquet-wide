#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// patternID
struct PatternId {

    static constexpr const char* name = "Pattern Id";
    static constexpr std::size_t size =  2;
static const std::uint16_t no_value = 65535;

    // default constructor
    constexpr PatternId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PatternId(const std::uint16_t value)
     : value{ value } {}

    // get value of PatternId field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
