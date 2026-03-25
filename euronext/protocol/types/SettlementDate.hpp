#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// settlementDate
struct SettlementDate {

    static constexpr const char* name = "Settlement Date";
    static constexpr std::size_t size =  2;
    using type = std::uint16_t;
static const type no_value = 65535;

    // default constructor
    constexpr SettlementDate()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit SettlementDate(const std::uint16_t value)
     : value{ value } {}

    // get value of SettlementDate field
    [[nodiscard]] std::uint16_t get() const {
        return value;
    }

  protected:
    std::uint16_t value;
};
}
