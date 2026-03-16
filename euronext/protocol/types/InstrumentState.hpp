#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// instrumentState
struct InstrumentState {

    static constexpr const char* name = "Instrument State";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr InstrumentState()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit InstrumentState(const std::uint8_t value)
     : value{ value } {}

    // get value of InstrumentState field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
