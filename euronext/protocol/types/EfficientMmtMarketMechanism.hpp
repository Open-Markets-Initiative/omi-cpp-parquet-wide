#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTMarketMechanism
struct EfficientMmtMarketMechanism {

    static constexpr const char* name = "Efficient Mmt Market Mechanism";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr EfficientMmtMarketMechanism()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtMarketMechanism(const std::uint8_t value)
     : value{ value } {}

    // get value of EfficientMmtMarketMechanism field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
