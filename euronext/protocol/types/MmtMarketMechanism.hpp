#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mMTMarketMechanism
struct MmtMarketMechanism {

    static constexpr const char* name = "Mmt Market Mechanism";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;
    static const type no_value = 255;

    // default constructor
    constexpr MmtMarketMechanism()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MmtMarketMechanism(const std::uint8_t value)
     : value{ value } {}

    // get value of MmtMarketMechanism field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
