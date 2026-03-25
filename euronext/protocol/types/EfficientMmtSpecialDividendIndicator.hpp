#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTSpecialDividendIndicator
struct EfficientMmtSpecialDividendIndicator {

    static constexpr const char* name = "Efficient Mmt Special Dividend Indicator";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr EfficientMmtSpecialDividendIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtSpecialDividendIndicator(const char value)
     : value{ value } {}

    // get value of EfficientMmtSpecialDividendIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
