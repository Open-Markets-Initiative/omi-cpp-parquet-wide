#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// tradeType
struct TradeType {

    static constexpr const char* name = "Trade Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr TradeType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TradeType(const std::uint8_t value)
     : value{ value } {}

    // get value of TradeType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
