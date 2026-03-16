#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// eventTime
struct EventTime {

    static constexpr const char* name = "Event Time";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;

    // default constructor
    constexpr EventTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EventTime(const std::uint64_t value)
     : value{ value } {}

    // get value of EventTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
