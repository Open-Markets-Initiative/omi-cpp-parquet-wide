#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// contractTradingType
struct ContractTradingType {

    static constexpr const char* name = "Contract Trading Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ContractTradingType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ContractTradingType(const std::uint8_t value)
     : value{ value } {}

    // get value of ContractTradingType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
