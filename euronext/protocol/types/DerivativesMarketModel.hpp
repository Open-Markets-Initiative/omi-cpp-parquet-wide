#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// derivativesMarketModel
struct DerivativesMarketModel {

    static constexpr const char* name = "Derivatives Market Model";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr DerivativesMarketModel()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DerivativesMarketModel(const std::uint8_t value)
     : value{ value } {}

    // get value of DerivativesMarketModel field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
