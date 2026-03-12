#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Equity And Index End Of Day Summary Message
struct EquityAndIndexEndOfDaySummary {

    static constexpr const char* name = "Equity And Index End Of Day Summary";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr EquityAndIndexEndOfDaySummary()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EquityAndIndexEndOfDaySummary(const char value)
     : value{ value } {}

    // get value of EquityAndIndexEndOfDaySummary field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
