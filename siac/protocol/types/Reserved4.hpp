#pragma once

#include <bit>
#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_2 {

// Four Reserved Bytes
struct Reserved4 {

    static constexpr const char* name = "Reserved 4";
    static constexpr std::size_t size = 4;
    using type = std::uint32_t;

    // default constructor
    constexpr Reserved4()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Reserved4(const std::uint32_t value)
     : value{ std::byteswap(value) } {}

    // get value of Reserved4 field
    [[nodiscard]] std::uint32_t get() const {
        return std::byteswap(value);
    }

  protected:
    std::uint32_t value;
};
}
