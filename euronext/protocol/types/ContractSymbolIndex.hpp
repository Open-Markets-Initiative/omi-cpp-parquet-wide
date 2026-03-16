#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// contractSymbolIndex
struct ContractSymbolIndex {

    static constexpr const char* name = "Contract Symbol Index";
    static constexpr std::size_t size =  4;

    // default constructor
    constexpr ContractSymbolIndex()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ContractSymbolIndex(const std::uint32_t value)
     : value{ value } {}

    // get value of ContractSymbolIndex field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
