#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// transparencyIndicator
struct TransparencyIndicator {

    static constexpr const char* name = "Transparency Indicator";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr TransparencyIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TransparencyIndicator(const std::uint8_t value)
     : value{ value } {}

    // get value of TransparencyIndicator field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
