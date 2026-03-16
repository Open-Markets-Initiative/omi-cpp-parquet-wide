#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// instrumentEventDate
struct InstrumentEventDate {

    static constexpr const char* name = "Instrument Event Date";
    static constexpr std::size_t size =  2;

    // default constructor
    constexpr InstrumentEventDate()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit InstrumentEventDate(const std::uint16_t value)
     : value{ value } {}

    // get value of InstrumentEventDate field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
