#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// rebroadcastIndicator
struct RebroadcastIndicator {

    static constexpr const char* name = "Rebroadcast Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr RebroadcastIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit RebroadcastIndicator(const std::uint8_t value)
     : value{ value } {}

    // get value of RebroadcastIndicator field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
