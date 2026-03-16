#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// lowLevel
struct LowLevel {

    static constexpr const char* name = "Low Level";
    static constexpr std::size_t size =  8;

    // default constructor
    constexpr LowLevel()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LowLevel(const std::int64_t value)
     : value{ value } {}

    // get value of LowLevel field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
