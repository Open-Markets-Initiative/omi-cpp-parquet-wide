#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// openedClosedFund
struct OpenedClosedFund {

    static constexpr const char* name = "Opened Closed Fund";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr OpenedClosedFund()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit OpenedClosedFund(const char value)
     : value{ value } {}

    // get value of OpenedClosedFund field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
