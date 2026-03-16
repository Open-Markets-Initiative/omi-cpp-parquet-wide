#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// lowTime
struct LowTime {

    static constexpr const char* name = "Low Time";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;

    // default constructor
    constexpr LowTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LowTime(const std::uint64_t value)
     : value{ value } {}

    // get value of LowTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
