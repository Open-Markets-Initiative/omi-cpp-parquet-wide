#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// pegOffset
struct PegOffset {

    static constexpr const char* name = "Peg Offset";
    static constexpr std::size_t size = 1;
    static const std::int8_t no_value = -128;

    // default constructor
    constexpr PegOffset()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PegOffset(const std::int8_t value)
     : value{ value } {}

    // get value of PegOffset field
    [[nodiscard]] std::int8_t get() const {
        return value;
    }

  protected:
    std::int8_t value;
};
}
