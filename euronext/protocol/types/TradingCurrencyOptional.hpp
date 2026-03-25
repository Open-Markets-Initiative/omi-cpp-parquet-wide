#pragma once

#include <array>
#include <cstddef>
#include <string>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// tradingCurrency
struct TradingCurrencyOptional {

    static constexpr auto name = "Trading Currency Optional";
    static constexpr std::size_t size = 3;

    // underlying type
    using type = std::array<char, size>;
static const type no_value = 0;

    // default constructor
    constexpr TradingCurrencyOptional()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit TradingCurrencyOptional(const type &value)
     : value{ value } {}

    // get value of TradingCurrencyOptional field
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
