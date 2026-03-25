#pragma once

#include <cstddef>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// blockTradeCode
struct BlockTradeCode {

    static constexpr const char* name = "Block Trade Code";
    static constexpr std::size_t size = 1;

    static const type no_value = 0;
    // default constructor
    constexpr BlockTradeCode()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit BlockTradeCode(const char value)
     : value{ value } {}

    // get value of BlockTradeCode field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
