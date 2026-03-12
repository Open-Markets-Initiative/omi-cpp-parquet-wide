#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Control Message
struct Control {

    static constexpr const char* name = "Control";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr Control()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Control(const char value)
     : value{ value } {}

    // get value of Control field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
