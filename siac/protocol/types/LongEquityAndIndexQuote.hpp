#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Long Equity And Index Quote Message
struct LongEquityAndIndexQuote {

    static constexpr const char* name = "Long Equity And Index Quote";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr LongEquityAndIndexQuote()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LongEquityAndIndexQuote(const char value)
     : value{ value } {}

    // get value of LongEquityAndIndexQuote field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
