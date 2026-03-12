#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Administrative Message
struct Administrative {

    static constexpr const char* name = "Administrative";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr Administrative()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Administrative(const char value)
     : value{ value } {}

    // get value of Administrative field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
