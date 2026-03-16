#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// blockLength
struct BlockLengthShort {

    static constexpr const char* name = "Block Length Short";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr BlockLengthShort()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BlockLengthShort(const std::uint8_t value)
     : value{ value } {}

    // get value of BlockLengthShort field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
