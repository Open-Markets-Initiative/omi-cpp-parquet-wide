#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTContributiontoPrice
struct EfficientMmtContributiontoPrice {

    static constexpr const char* name = "Efficient Mmt Contributionto Price";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr EfficientMmtContributiontoPrice()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtContributiontoPrice(const char value)
     : value{ value } {}

    // get value of EfficientMmtContributiontoPrice field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
