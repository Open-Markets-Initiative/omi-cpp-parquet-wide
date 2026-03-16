#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// endTimeVwap
struct EndTimeVwap {

    static constexpr const char* name = "End Time Vwap";
    static constexpr std::size_t size =  4;
static const std::uint32_t no_value = 4294967295;

    // default constructor
    constexpr EndTimeVwap()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EndTimeVwap(const std::uint32_t value)
     : value{ value } {}

    // get value of EndTimeVwap field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
