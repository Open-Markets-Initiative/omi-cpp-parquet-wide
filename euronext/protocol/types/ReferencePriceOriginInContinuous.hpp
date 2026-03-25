#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// referencePriceOriginInContinuous
struct ReferencePriceOriginInContinuous {

    static constexpr const char* name = "Reference Price Origin In Continuous";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr ReferencePriceOriginInContinuous()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ReferencePriceOriginInContinuous(const std::uint8_t value)
     : value{ value } {}

    // get value of ReferencePriceOriginInContinuous field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
