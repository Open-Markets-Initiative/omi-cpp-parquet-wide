#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTAlgorithmicIndicator
struct EfficientMmtAlgorithmicIndicator {

    static constexpr const char* name = "Efficient Mmt Algorithmic Indicator";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr EfficientMmtAlgorithmicIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtAlgorithmicIndicator(const char value)
     : value{ value } {}

    // get value of EfficientMmtAlgorithmicIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
