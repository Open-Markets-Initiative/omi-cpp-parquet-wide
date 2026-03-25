#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// statsUpdateValue
struct StatsUpdateValue {

    static constexpr const char* name = "Stats Update Value";
    static constexpr std::size_t size =  8;
    using type = std::int64_t;
static const type no_value = -9223372036854775808;

    // default constructor
    constexpr StatsUpdateValue()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StatsUpdateValue(const std::int64_t value)
     : value{ value } {}

    // get value of StatsUpdateValue field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
