#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// contractName
struct ContractName {

    static constexpr auto name = "Contract Name";
    static constexpr std::size_t size = 60;

    // underlying type
    using type = std::array<char, size>;

    // default constructor
    constexpr ContractName()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ContractName(const type &value)
     : value{ value } {}

    // get value of ContractName field
    [[nodiscard]] std::string get() const {
        return std::string{value.data(), length()};
    }

    // runtime length of field
    [[nodiscard]] std::size_t length() const {
        std::size_t index = 0;
        for (; index < size; ++index) {
            if (value[index] == ' ') { break; }
        }

        return index;
    }

  protected:
    type value;
};
}
