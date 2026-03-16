#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// startTimeVwap
struct StartTimeVwap {

    static constexpr const char* name = "Start Time Vwap";
    static constexpr std::size_t size =  4;
static const std::uint32_t no_value = 4294967295;

    // default constructor
    constexpr StartTimeVwap()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StartTimeVwap(const std::uint32_t value)
     : value{ value } {}

    // get value of StartTimeVwap field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
