#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// nAVPrice
struct NavPrice {

    static constexpr const char* name = "Nav Price";
    static constexpr std::size_t size =  8;
static const std::int64_t no_value = -9223372036854775808;

    // default constructor
    constexpr NavPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit NavPrice(const std::int64_t value)
     : value{ value } {}

    // get value of NavPrice field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
