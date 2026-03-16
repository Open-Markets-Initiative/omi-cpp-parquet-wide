#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// statusReason
struct StatusReason {

    static constexpr const char* name = "Status Reason";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr StatusReason()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StatusReason(const std::uint8_t value)
     : value{ value } {}

    // get value of StatusReason field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
