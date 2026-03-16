#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// legRatio
struct LegRatio {

    static constexpr const char* name = "Leg Ratio";
    static constexpr std::size_t size =  4;

    // default constructor
    constexpr LegRatio()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LegRatio(const std::uint32_t value)
     : value{ value } {}

    // get value of LegRatio field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
