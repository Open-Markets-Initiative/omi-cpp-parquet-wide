#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// highLevel
struct HighLevel {

    static constexpr const char* name = "High Level";
    static constexpr std::size_t size =  8;

    // default constructor
    constexpr HighLevel()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit HighLevel(const std::int64_t value)
     : value{ value } {}

    // get value of HighLevel field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
