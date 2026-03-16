#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mMTOffBookAutomatedIndicator
struct MmtOffBookAutomatedIndicator {

    static constexpr const char* name = "Mmt Off Book Automated Indicator";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr MmtOffBookAutomatedIndicator()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MmtOffBookAutomatedIndicator(const char value)
     : value{ value } {}

    // get value of MmtOffBookAutomatedIndicator field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
