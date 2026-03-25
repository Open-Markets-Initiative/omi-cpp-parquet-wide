#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// retransmissionEndTime
struct RetransmissionEndTime {

    static constexpr const char* name = "Retransmission End Time";
    static constexpr std::size_t size = 8;

    // underlying type
    using type = std::uint64_t;
    static const type no_value = 18446744073709551615;

    // default constructor
    constexpr RetransmissionEndTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit RetransmissionEndTime(const std::uint64_t value)
     : value{ value } {}

    // get value of RetransmissionEndTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    type value;
};
}
