#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// session
struct Session {

    static constexpr const char* name = "Session";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr Session()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Session(const std::uint8_t value)
     : value{ value } {}

    // get value of Session field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
