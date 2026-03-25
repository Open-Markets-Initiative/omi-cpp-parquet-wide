#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_2 {

// One Reserved Byte
struct Reserved1 {

    static constexpr const char* name = "Reserved 1";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr Reserved1()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Reserved1(const std::uint8_t value)
     : value{ value } {}

    // get value of Reserved1 field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
