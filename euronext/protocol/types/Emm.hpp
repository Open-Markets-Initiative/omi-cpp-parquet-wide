#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// eMM
struct Emm {

    static constexpr const char* name = "Emm";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr Emm()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit Emm(const std::uint8_t value)
     : value{ value } {}

    // get value of Emm field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
