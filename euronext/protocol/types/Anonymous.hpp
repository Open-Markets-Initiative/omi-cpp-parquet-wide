#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// anonymous
struct Anonymous {

    static constexpr const char* name = "Anonymous";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr Anonymous()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Anonymous(const std::uint8_t value)
     : value{ value } {}

    // get value of Anonymous field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
