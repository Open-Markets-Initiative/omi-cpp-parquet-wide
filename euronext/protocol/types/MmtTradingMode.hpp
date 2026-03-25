#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mMTTradingMode
struct MmtTradingMode {

    static constexpr const char* name = "Mmt Trading Mode";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr MmtTradingMode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MmtTradingMode(const char value)
     : value{ value } {}

    // get value of MmtTradingMode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
