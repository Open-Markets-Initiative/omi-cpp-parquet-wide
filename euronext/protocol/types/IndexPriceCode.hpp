#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// indexPriceCode
struct IndexPriceCode {

    static constexpr const char* name = "Index Price Code";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr IndexPriceCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit IndexPriceCode(const std::uint8_t value)
     : value{ value } {}

    // get value of IndexPriceCode field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
