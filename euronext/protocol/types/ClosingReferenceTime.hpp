#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// closingReferenceTime
struct ClosingReferenceTime {

    static constexpr const char* name = "Closing Reference Time";
    static constexpr std::size_t size =  8;
    using type = std::uint64_t;

    // default constructor
    constexpr ClosingReferenceTime()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ClosingReferenceTime(const std::uint64_t value)
     : value{ value } {}

    // get value of ClosingReferenceTime field
    [[nodiscard]] std::uint64_t get() const {
        return value;
    }

  protected:
    std::uint64_t value;
};
}
