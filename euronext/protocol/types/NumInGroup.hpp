#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// numInGroup
struct NumInGroup {

    static constexpr const char* name = "Num In Group";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr NumInGroup()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit NumInGroup(const std::uint8_t value)
     : value{ value } {}

    // get value of NumInGroup field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
