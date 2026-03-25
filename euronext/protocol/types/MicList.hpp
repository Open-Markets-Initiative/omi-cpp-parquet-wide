#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mICList
struct MicList {

    static constexpr auto name = "Mic List";
    static constexpr std::size_t size = 20;

    // underlying type
    using type = std::array<char, size>;
static const type no_value = 0;

    // default constructor
    constexpr MicList()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MicList(const type &value)
     : value{ value } {}

    // get value of MicList field
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
