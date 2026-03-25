#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mMTModificationIndicator
struct MmtModificationIndicatorChar4Optional {

    static constexpr auto name = "Mmt Modification Indicator char 4 optional";
    static constexpr std::size_t size = 4;

    // underlying type
    using type = std::array<char, size>;
static const type no_value = 0;

    // default constructor
    constexpr MmtModificationIndicatorChar4Optional()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MmtModificationIndicatorChar4Optional(const type &value)
     : value{ value } {}

    // get value of MmtModificationIndicatorChar4Optional field
    [[nodiscard]] std::string get() const {
        return std::string{value.data(), length()};
    }

    // runtime length of field
    [[nodiscard]] std::size_t length() const {
        std::size_t index = 0;
        for (; index < size; ++index) {
            if (value[index] == ' ') { break; }
        }

        return index;
    }

  protected:
    type value;
};
}
