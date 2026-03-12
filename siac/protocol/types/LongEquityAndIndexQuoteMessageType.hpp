#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Long Equity And Index Quote Message Type
struct LongEquityAndIndexQuoteMessageType {

    static constexpr const char* name = "Long Equity And Index Quote Message Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr LongEquityAndIndexQuoteMessageType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LongEquityAndIndexQuoteMessageType(const char value)
     : value{ value } {}

    // get value of LongEquityAndIndexQuoteMessageType field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
