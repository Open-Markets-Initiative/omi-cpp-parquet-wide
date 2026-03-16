#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// ratioDecimals
struct RatioDecimals {

    static constexpr const char* name = "Ratio Decimals";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr RatioDecimals()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit RatioDecimals(const std::uint8_t value)
     : value{ value } {}

    // get value of RatioDecimals field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
