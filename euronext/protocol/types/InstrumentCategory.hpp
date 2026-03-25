#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// instrumentCategory
struct InstrumentCategory {

    static constexpr const char* name = "Instrument Category";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr InstrumentCategory()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit InstrumentCategory(const std::uint8_t value)
     : value{ value } {}

    // get value of InstrumentCategory field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
