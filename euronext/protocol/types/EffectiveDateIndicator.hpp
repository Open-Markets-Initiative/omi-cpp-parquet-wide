#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// effectiveDateIndicator
struct EffectiveDateIndicator {

    static constexpr const char* name = "Effective Date Indicator";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr EffectiveDateIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EffectiveDateIndicator(const std::uint8_t value)
     : value{ value } {}

    // get value of EffectiveDateIndicator field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
