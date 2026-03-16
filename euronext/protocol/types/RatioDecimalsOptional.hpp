#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// ratioDecimals
struct RatioDecimalsOptional {

    static constexpr const char* name = "Ratio Decimals Optional";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr RatioDecimalsOptional()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit RatioDecimalsOptional(const std::uint8_t value)
     : value{ value } {}

    // get value of RatioDecimalsOptional field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
