#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTOffBookAutomatedIndicator
struct EfficientMmtOffBookAutomatedIndicator {

    static constexpr const char* name = "Efficient Mmt Off Book Automated Indicator";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr EfficientMmtOffBookAutomatedIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtOffBookAutomatedIndicator(const char value)
     : value{ value } {}

    // get value of EfficientMmtOffBookAutomatedIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
