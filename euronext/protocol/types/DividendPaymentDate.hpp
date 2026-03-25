#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// dividendPaymentDate
struct DividendPaymentDate {

    static constexpr const char* name = "Dividend Payment Date";
    static constexpr std::size_t size =  2;
    using type = std::uint16_t;
static const type no_value = 65535;

    // default constructor
    constexpr DividendPaymentDate()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DividendPaymentDate(const std::uint16_t value)
     : value{ value } {}

    // get value of DividendPaymentDate field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
