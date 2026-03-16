#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// indexLevelType
struct IndexLevelType {

    static constexpr const char* name = "Index Level Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr IndexLevelType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit IndexLevelType(const std::uint8_t value)
     : value{ value } {}

    // get value of IndexLevelType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
