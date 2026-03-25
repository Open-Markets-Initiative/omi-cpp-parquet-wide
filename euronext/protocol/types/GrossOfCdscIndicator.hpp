#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// grossOfCDSCIndicator
struct GrossOfCdscIndicator {

    static constexpr const char* name = "Gross Of Cdsc Indicator";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr GrossOfCdscIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit GrossOfCdscIndicator(const char value)
     : value{ value } {}

    // get value of GrossOfCdscIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
