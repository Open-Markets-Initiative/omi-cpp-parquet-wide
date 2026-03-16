#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTTradingMode
struct EfficientMmtTradingMode {

    static constexpr const char* name = "Efficient Mmt Trading Mode";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr EfficientMmtTradingMode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtTradingMode(const char value)
     : value{ value } {}

    // get value of EfficientMmtTradingMode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
