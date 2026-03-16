#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// eMM
struct EmmOptional {

    static constexpr const char* name = "Emm Optional";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr EmmOptional()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EmmOptional(const std::uint8_t value)
     : value{ value } {}

    // get value of EmmOptional field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
