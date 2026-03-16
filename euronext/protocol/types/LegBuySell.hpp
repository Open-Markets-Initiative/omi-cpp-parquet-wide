#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// legBuySell
struct LegBuySell {

    static constexpr const char* name = "Leg Buy Sell";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr LegBuySell()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LegBuySell(const char value)
     : value{ value } {}

    // get value of LegBuySell field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
