#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// lotSize
struct LotSize {

    static constexpr const char* name = "Lot Size";
    static constexpr std::size_t size =  8;
    using type = std::uint64_t;

    // default constructor
    constexpr LotSize()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit LotSize(const std::uint64_t value)
     : value{ value } {}

    // get value of LotSize field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
