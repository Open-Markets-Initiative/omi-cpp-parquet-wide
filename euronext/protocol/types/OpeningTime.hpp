#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// openingTime
struct OpeningTime {

    static constexpr const char* name = "Opening Time";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;

    // default constructor
    constexpr OpeningTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OpeningTime(const std::uint64_t value)
     : value{ value } {}

    // get value of OpeningTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
