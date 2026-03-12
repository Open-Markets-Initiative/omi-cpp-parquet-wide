#pragma once

#include <cstddef>
#include <cstdint>

namespace siac::opra::recipient::obi::v6_2 {

// Opra packet timestamp
struct BlockTimestamp {

    static constexpr const char* name = "Block Timestamp";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;

    // default constructor
    constexpr BlockTimestamp()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BlockTimestamp(const std::uint64_t value)
     : value{ value } {}

    // get value of BlockTimestamp field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
