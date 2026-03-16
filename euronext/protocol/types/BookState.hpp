#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// bookState
struct BookState {

    static constexpr const char* name = "Book State";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr BookState()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BookState(const std::uint8_t value)
     : value{ value } {}

    // get value of BookState field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
