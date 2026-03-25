#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// optiqSegment
struct OptiqSegment {

    static constexpr const char* name = "Optiq Segment";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr OptiqSegment()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OptiqSegment(const std::uint8_t value)
     : value{ value } {}

    // get value of OptiqSegment field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
