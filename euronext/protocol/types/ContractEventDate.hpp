#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// contractEventDate
struct ContractEventDate {

    static constexpr const char* name = "Contract Event Date";
    static constexpr std::size_t size =  2;
static const std::uint16_t no_value = 65535;

    // default constructor
    constexpr ContractEventDate()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ContractEventDate(const std::uint16_t value)
     : value{ value } {}

    // get value of ContractEventDate field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
