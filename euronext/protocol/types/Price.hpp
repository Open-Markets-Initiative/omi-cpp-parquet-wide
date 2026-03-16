#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// price
struct Price {

    static constexpr const char* name = "Price";
    static constexpr std::size_t size =  8;
static const std::int64_t no_value = -9223372036854775808;

    // default constructor
    constexpr Price()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Price(const std::int64_t value)
     : value{ value } {}

    // get value of Price field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
