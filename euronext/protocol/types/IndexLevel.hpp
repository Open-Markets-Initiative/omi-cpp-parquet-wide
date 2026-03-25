#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// indexLevel
struct IndexLevel {

    static constexpr const char* name = "Index Level";
    static constexpr std::size_t size =  8;
    using type = std::int64_t;

    // default constructor
    constexpr IndexLevel()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit IndexLevel(const std::int64_t value)
     : value{ value } {}

    // get value of IndexLevel field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
