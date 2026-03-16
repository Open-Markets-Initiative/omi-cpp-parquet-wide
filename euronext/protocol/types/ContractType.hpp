#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// contractType
struct ContractType {

    static constexpr const char* name = "Contract Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ContractType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ContractType(const char value)
     : value{ value } {}

    // get value of ContractType field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
