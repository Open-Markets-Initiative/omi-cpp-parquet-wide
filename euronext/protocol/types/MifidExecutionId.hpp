#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// mifidExecutionID
struct MifidExecutionId {

    static constexpr auto name = "Mifid Execution Id";
    static constexpr std::size_t size = 52;

    // underlying type
    using type = std::array<char, size>;

    // default constructor
    constexpr MifidExecutionId()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit MifidExecutionId(const type &value)
     : value{ value } {}

    // get value of MifidExecutionId field
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
