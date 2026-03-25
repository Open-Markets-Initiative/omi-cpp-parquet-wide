#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// lastNAVPrice
struct LastNavPrice {

    static constexpr const char* name = "Last Nav Price";
    static constexpr std::size_t size =  8;
    using type = std::int64_t;
static const type no_value = -9223372036854775808;

    // default constructor
    constexpr LastNavPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LastNavPrice(const std::int64_t value)
     : value{ value } {}

    // get value of LastNavPrice field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
