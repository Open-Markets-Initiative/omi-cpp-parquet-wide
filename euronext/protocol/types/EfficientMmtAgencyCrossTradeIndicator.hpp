#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTAgencyCrossTradeIndicator
struct EfficientMmtAgencyCrossTradeIndicator {

    static constexpr const char* name = "Efficient Mmt Agency Cross Trade Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr EfficientMmtAgencyCrossTradeIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtAgencyCrossTradeIndicator(const char value)
     : value{ value } {}

    // get value of EfficientMmtAgencyCrossTradeIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
