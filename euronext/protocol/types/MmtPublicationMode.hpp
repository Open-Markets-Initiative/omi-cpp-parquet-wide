#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mMTPublicationMode
struct MmtPublicationMode {

    static constexpr auto name = "Mmt Publication Mode";
    static constexpr std::size_t size = 4;

    // underlying type
    using type = std::array<char, size>;
static const type no_value = 0;

    // default constructor
    constexpr MmtPublicationMode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MmtPublicationMode(const type &value)
     : value{ value } {}

    // get value of MmtPublicationMode field
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
