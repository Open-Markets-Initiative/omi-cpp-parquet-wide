#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// openingLevel
struct OpeningLevel {

    static constexpr const char* name = "Opening Level";
    static constexpr std::size_t size =  8;
    using type = std::int64_t;

    // default constructor
    constexpr OpeningLevel()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OpeningLevel(const std::int64_t value)
     : value{ value } {}

    // get value of OpeningLevel field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
