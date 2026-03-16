#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// underlyingType
struct UnderlyingType {

    static constexpr const char* name = "Underlying Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr UnderlyingType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UnderlyingType(const char value)
     : value{ value } {}

    // get value of UnderlyingType field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
