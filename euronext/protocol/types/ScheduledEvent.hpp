#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// scheduledEvent
struct ScheduledEvent {

    static constexpr const char* name = "Scheduled Event";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr ScheduledEvent()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ScheduledEvent(const std::uint8_t value)
     : value{ value } {}

    // get value of ScheduledEvent field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
