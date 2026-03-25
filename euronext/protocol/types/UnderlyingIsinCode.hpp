#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// underlyingISINCode
struct UnderlyingIsinCode {

    static constexpr auto name = "Underlying Isin Code";
    static constexpr std::size_t size = 12;

    // underlying type
    using type = std::array<char, size>;
static const type no_value = 0;

    // default constructor
    constexpr UnderlyingIsinCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit UnderlyingIsinCode(const type &value)
     : value{ value } {}

    // get value of UnderlyingIsinCode field
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
