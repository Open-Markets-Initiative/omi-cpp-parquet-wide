#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// underlyingSymbolIndex
struct UnderlyingSymbolIndex {

    static constexpr const char* name = "Underlying Symbol Index";
    static constexpr std::size_t size =  4;
static const std::uint32_t no_value = 4294967295;

    // default constructor
    constexpr UnderlyingSymbolIndex()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UnderlyingSymbolIndex(const std::uint32_t value)
     : value{ value } {}

    // get value of UnderlyingSymbolIndex field
    [[nodiscard]] std::uint32_t get() const {
        return value;
    }

  protected:
    std::uint32_t value;
};
}
