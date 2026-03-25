#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// underlyingExpiry
struct UnderlyingExpiry {

    static constexpr const char* name = "Underlying Expiry";
    static constexpr std::size_t size =  4;
    using type = std::uint32_t;
static const type no_value = 4294967295;

    // default constructor
    constexpr UnderlyingExpiry()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UnderlyingExpiry(const std::uint32_t value)
     : value{ value } {}

    // get value of UnderlyingExpiry field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
