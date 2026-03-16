#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// tradingPeriod
struct TradingPeriod {

    static constexpr const char* name = "Trading Period";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr TradingPeriod()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TradingPeriod(const std::uint8_t value)
     : value{ value } {}

    // get value of TradingPeriod field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
