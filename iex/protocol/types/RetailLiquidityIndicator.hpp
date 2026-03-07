#pragma once

#include <cstddef>

namespace iex::equities::tops::iextp::v1_6_6 {

// Retail Liquidity Indicator identifier
struct RetailLiquidityIndicator {

    static constexpr const char* name = "Retail Liquidity Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr RetailLiquidityIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit RetailLiquidityIndicator(const char value)
     : value{ value } {}

    // get value of RetailLiquidityIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
