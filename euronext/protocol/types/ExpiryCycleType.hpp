#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// expiryCycleType
struct ExpiryCycleType {

    static constexpr const char* name = "Expiry Cycle Type";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr ExpiryCycleType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ExpiryCycleType(const std::uint8_t value)
     : value{ value } {}

    // get value of ExpiryCycleType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
