#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// accountType
struct AccountType {

    static constexpr const char* name = "Account Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr AccountType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit AccountType(const std::uint8_t value)
     : value{ value } {}

    // get value of AccountType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
