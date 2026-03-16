#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// taxDescriptionAttachingToADividend
struct TaxDescriptionAttachingToADividend {

    static constexpr const char* name = "Tax Description Attaching To A Dividend";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr TaxDescriptionAttachingToADividend()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TaxDescriptionAttachingToADividend(const char value)
     : value{ value } {}

    // get value of TaxDescriptionAttachingToADividend field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
