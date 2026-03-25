#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// instUnitExp
struct InstUnitExp {

    static constexpr const char* name = "Inst Unit Exp";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr InstUnitExp()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit InstUnitExp(const std::uint8_t value)
     : value{ value } {}

    // get value of InstUnitExp field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
