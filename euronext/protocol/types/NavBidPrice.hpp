#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// nAVBidPrice
struct NavBidPrice {

    static constexpr const char* name = "Nav Bid Price";
    static constexpr std::size_t size =  8;
    using type = std::int64_t;
static const type no_value = -9223372036854775808;

    // default constructor
    constexpr NavBidPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit NavBidPrice(const std::int64_t value)
     : value{ value } {}

    // get value of NavBidPrice field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
