#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// exchangeCode
struct ExchangeCode {

    static constexpr const char* name = "Exchange Code";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ExchangeCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ExchangeCode(const char value)
     : value{ value } {}

    // get value of ExchangeCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
