#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// dividendRecordDate
struct DividendRecordDate {

    static constexpr const char* name = "Dividend Record Date";
    static constexpr std::size_t size =  2;
static const std::uint16_t no_value = 65535;

    // default constructor
    constexpr DividendRecordDate()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit DividendRecordDate(const std::uint16_t value)
     : value{ value } {}

    // get value of DividendRecordDate field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
