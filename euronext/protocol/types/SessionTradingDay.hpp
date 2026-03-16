#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// sessionTradingDay
struct SessionTradingDay {

    static constexpr const char* name = "Session Trading Day";
    static constexpr std::size_t size =  2;

    // default constructor
    constexpr SessionTradingDay()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit SessionTradingDay(const std::uint16_t value)
     : value{ value } {}

    // get value of SessionTradingDay field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
