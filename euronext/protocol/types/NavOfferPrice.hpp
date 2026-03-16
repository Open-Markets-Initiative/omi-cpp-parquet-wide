#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// nAVOfferPrice
struct NavOfferPrice {

    static constexpr const char* name = "Nav Offer Price";
    static constexpr std::size_t size =  8;
static const std::int64_t no_value = -9223372036854775808;

    // default constructor
    constexpr NavOfferPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit NavOfferPrice(const std::int64_t value)
     : value{ value } {}

    // get value of NavOfferPrice field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
