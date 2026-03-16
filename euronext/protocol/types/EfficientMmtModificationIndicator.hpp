#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTModificationIndicator
struct EfficientMmtModificationIndicator {

    static constexpr const char* name = "Efficient Mmt Modification Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr EfficientMmtModificationIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtModificationIndicator(const char value)
     : value{ value } {}

    // get value of EfficientMmtModificationIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
