#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// quoteUpdateType
struct QuoteUpdateType {

    static constexpr const char* name = "Quote Update Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr QuoteUpdateType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit QuoteUpdateType(const std::uint8_t value)
     : value{ value } {}

    // get value of QuoteUpdateType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
