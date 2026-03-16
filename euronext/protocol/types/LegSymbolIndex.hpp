#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// legSymbolIndex
struct LegSymbolIndex {

    static constexpr const char* name = "Leg Symbol Index";
    static constexpr std::size_t size =  4;

    // default constructor
    constexpr LegSymbolIndex()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LegSymbolIndex(const std::uint32_t value)
     : value{ value } {}

    // get value of LegSymbolIndex field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
