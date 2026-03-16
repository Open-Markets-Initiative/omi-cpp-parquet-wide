#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// updateType
struct UpdateType {

    static constexpr const char* name = "Update Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr UpdateType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UpdateType(const std::uint8_t value)
     : value{ value } {}

    // get value of UpdateType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
