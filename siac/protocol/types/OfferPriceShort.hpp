#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_2 {

// Represents The Price At Which A Seller Is Offering To Sell An Option
struct OfferPriceShort {

    static constexpr const char* name = "Offer Price Short";
    static constexpr std::size_t size = 2;
    static constexpr std::size_t precision = 2;
    static constexpr double denominator = 100;
    using type = std::int16_t;

    // default constructor
    constexpr OfferPriceShort()
     : value{ 0 } {}

    // constructor for OfferPriceShort field
    constexpr explicit OfferPriceShort(const std::int16_t value)
     : value{ std::byteswap(value) } {}

    // get underlying integer of OfferPriceShort field
    [[nodiscard]] std::int16_t integer() const {
        return std::byteswap(value);
    }

    // get  value of OfferPriceShort field
    [[nodiscard]] double get() const {
        return integer() / denominator;
    }

  protected:
    std::int16_t value;
};
}
