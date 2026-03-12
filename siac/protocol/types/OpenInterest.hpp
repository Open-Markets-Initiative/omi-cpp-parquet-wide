#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Open Interest Message
struct OpenInterest {

    static constexpr const char* name = "Open Interest";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr OpenInterest()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OpenInterest(const char value)
     : value{ value } {}

    // get value of OpenInterest field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
