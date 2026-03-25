#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// sEDOLCode
struct SedolCode {

    static constexpr auto name = "Sedol Code";
    static constexpr std::size_t size = 7;

    // underlying type
    using type = std::array<char, size>;
static const type no_value = 0;

    // default constructor
    constexpr SedolCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit SedolCode(const type &value)
     : value{ value } {}

    // get value of SedolCode field
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
