#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// phaseId
struct PhaseId {

    static constexpr const char* name = "Phase Id";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr PhaseId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit PhaseId(const std::uint8_t value)
     : value{ value } {}

    // get value of PhaseId field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
