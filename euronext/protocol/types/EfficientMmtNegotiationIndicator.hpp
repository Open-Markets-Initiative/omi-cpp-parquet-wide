#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTNegotiationIndicator
struct EfficientMmtNegotiationIndicator {

    static constexpr const char* name = "Efficient Mmt Negotiation Indicator";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr EfficientMmtNegotiationIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtNegotiationIndicator(const char value)
     : value{ value } {}

    // get value of EfficientMmtNegotiationIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
