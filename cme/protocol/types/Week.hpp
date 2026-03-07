#pragma once

#include <cstddef>
#include <cstdint>

namespace cme::mdp3::v8 {

// WW
struct Week {

    static constexpr const char* name = "Week";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr Week()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Week(const std::uint8_t value)
     : value{ value } {}

    // get value of Week field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
