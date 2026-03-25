#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// maxOrderAmountContinuous
struct MaxOrderAmountContinuous {

    static constexpr const char* name = "Max Order Amount Continuous";
    static constexpr std::size_t size =  8;
    using type = std::uint64_t;
static const type no_value = 18446744073709551615;

    // default constructor
    constexpr MaxOrderAmountContinuous()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MaxOrderAmountContinuous(const std::uint64_t value)
     : value{ value } {}

    // get value of MaxOrderAmountContinuous field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
