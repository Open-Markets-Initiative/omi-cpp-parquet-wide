#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// settlementMethod
struct SettlementMethod {

    static constexpr const char* name = "Settlement Method";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr SettlementMethod()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit SettlementMethod(const char value)
     : value{ value } {}

    // get value of SettlementMethod field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
