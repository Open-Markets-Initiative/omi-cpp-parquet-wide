#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_2 {

// Represents The Price At Which A Buyer Is Willing To Buy An Option
struct BidPriceShort {

    static constexpr const char* name = "Bid Price Short";
    static constexpr std::size_t size = 2;
    static constexpr std::size_t precision = 2;
    static constexpr double denominator = 100;
    using type = std::int16_t;

    // default constructor
    constexpr BidPriceShort()
     : value{ 0 } {}

    // constructor for BidPriceShort field
    constexpr explicit BidPriceShort(const std::int16_t value)
     : value{ std::byteswap(value) } {}

    // get underlying integer of BidPriceShort field
    [[nodiscard]] std::int16_t integer() const {
        return std::byteswap(value);
    }

    // get  value of BidPriceShort field
    [[nodiscard]] double get() const {
        return integer() / denominator;
    }

  protected:
    std::int16_t value;
};
}
