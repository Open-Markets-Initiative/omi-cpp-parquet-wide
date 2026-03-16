#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// typeOfMarketAdmission
struct TypeOfMarketAdmission {

    static constexpr const char* name = "Type Of Market Admission";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr TypeOfMarketAdmission()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TypeOfMarketAdmission(const char value)
     : value{ value } {}

    // get value of TypeOfMarketAdmission field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
