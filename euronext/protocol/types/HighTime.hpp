#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// highTime
struct HighTime {

    static constexpr const char* name = "High Time";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;

    // default constructor
    constexpr HighTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit HighTime(const std::uint64_t value)
     : value{ value } {}

    // get value of HighTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
