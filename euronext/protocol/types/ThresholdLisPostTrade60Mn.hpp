#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// thresholdLISPostTrade60mn
struct ThresholdLisPostTrade60Mn {

    static constexpr const char* name = "Threshold Lis Post Trade 60mn";
    static constexpr std::size_t size =  8;
    using type = std::uint64_t;
static const type no_value = 18446744073709551615;

    // default constructor
    constexpr ThresholdLisPostTrade60Mn()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ThresholdLisPostTrade60Mn(const std::uint64_t value)
     : value{ value } {}

    // get value of ThresholdLisPostTrade60Mn field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
