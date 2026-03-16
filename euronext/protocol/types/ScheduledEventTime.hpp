#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// scheduledEventTime
struct ScheduledEventTime {

    static constexpr const char* name = "Scheduled Event Time";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;
    static const std::uint64_t no_value = 18446744073709551615;

    // default constructor
    constexpr ScheduledEventTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ScheduledEventTime(const std::uint64_t value)
     : value{ value } {}

    // get value of ScheduledEventTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
