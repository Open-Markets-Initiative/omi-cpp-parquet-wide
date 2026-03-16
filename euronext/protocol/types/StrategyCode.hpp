#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// strategyCode
struct StrategyCode {

    static constexpr const char* name = "Strategy Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr StrategyCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StrategyCode(const char value)
     : value{ value } {}

    // get value of StrategyCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
