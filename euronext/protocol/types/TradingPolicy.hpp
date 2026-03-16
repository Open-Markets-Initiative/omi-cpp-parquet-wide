#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// tradingPolicy
struct TradingPolicy {

    static constexpr const char* name = "Trading Policy";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr TradingPolicy()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TradingPolicy(const std::uint8_t value)
     : value{ value } {}

    // get value of TradingPolicy field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
