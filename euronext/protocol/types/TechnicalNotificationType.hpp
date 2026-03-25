#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// technicalNotificationType
struct TechnicalNotificationType {

    static constexpr const char* name = "Technical Notification Type";
    static constexpr std::size_t size = 1;
    using type = std::uint8_t;

    // default constructor
    constexpr TechnicalNotificationType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TechnicalNotificationType(const std::uint8_t value)
     : value{ value } {}

    // get value of TechnicalNotificationType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
