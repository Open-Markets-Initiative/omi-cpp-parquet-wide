#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Equity And Index Last Sale Message
struct EquityAndIndexLastSale {

    static constexpr const char* name = "Equity And Index Last Sale";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr EquityAndIndexLastSale()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EquityAndIndexLastSale(const char value)
     : value{ value } {}

    // get value of EquityAndIndexLastSale field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
