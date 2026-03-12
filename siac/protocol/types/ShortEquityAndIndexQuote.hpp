#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Short Equity And Index Quote Message
struct ShortEquityAndIndexQuote {

    static constexpr const char* name = "Short Equity And Index Quote";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ShortEquityAndIndexQuote()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ShortEquityAndIndexQuote(const char value)
     : value{ value } {}

    // get value of ShortEquityAndIndexQuote field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
