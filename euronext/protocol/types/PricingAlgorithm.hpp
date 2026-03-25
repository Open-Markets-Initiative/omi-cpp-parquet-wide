#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// pricingAlgorithm
struct PricingAlgorithm {

    static constexpr const char* name = "Pricing Algorithm";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr PricingAlgorithm()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PricingAlgorithm(const std::uint8_t value)
     : value{ value } {}

    // get value of PricingAlgorithm field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
