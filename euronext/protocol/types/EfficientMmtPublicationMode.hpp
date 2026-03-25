#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// efficientMMTPublicationMode
struct EfficientMmtPublicationMode {

    static constexpr const char* name = "Efficient Mmt Publication Mode";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr EfficientMmtPublicationMode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit EfficientMmtPublicationMode(const char value)
     : value{ value } {}

    // get value of EfficientMmtPublicationMode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
