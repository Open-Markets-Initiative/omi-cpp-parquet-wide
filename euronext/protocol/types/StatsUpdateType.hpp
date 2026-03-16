#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// statsUpdateType
struct StatsUpdateType {

    static constexpr const char* name = "Stats Update Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr StatsUpdateType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit StatsUpdateType(const std::uint8_t value)
     : value{ value } {}

    // get value of StatsUpdateType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
