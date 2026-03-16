#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// collarMaxUnhaltNb
struct CollarMaxUnhaltNb {

    static constexpr const char* name = "Collar Max Unhalt Nb";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr CollarMaxUnhaltNb()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit CollarMaxUnhaltNb(const std::uint8_t value)
     : value{ value } {}

    // get value of CollarMaxUnhaltNb field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
