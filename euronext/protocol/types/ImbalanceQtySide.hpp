#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// imbalanceQtySide
struct ImbalanceQtySide {

    static constexpr const char* name = "Imbalance Qty Side";
    static constexpr std::size_t size = 1;
    static const std::uint8_t no_value = 255;

    // default constructor
    constexpr ImbalanceQtySide()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ImbalanceQtySide(const std::uint8_t value)
     : value{ value } {}

    // get value of ImbalanceQtySide field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
