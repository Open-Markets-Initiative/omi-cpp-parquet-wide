#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// fullInstrumentName
struct FullInstrumentName {

    static constexpr auto name = "Full Instrument Name";
    static constexpr std::size_t size = 102;

    // underlying type
    using type = std::array<char, size>;
static const type no_value = 0;

    // default constructor
    constexpr FullInstrumentName()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit FullInstrumentName(const type &value)
     : value{ value } {}

    // get value of FullInstrumentName field
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
