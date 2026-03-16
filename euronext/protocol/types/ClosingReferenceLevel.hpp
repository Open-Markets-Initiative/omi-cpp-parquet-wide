#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// closingReferenceLevel
struct ClosingReferenceLevel {

    static constexpr const char* name = "Closing Reference Level";
    static constexpr std::size_t size =  8;

    // default constructor
    constexpr ClosingReferenceLevel()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ClosingReferenceLevel(const std::int64_t value)
     : value{ value } {}

    // get value of ClosingReferenceLevel field
    [[nodiscard]] std::int64_t get() const {
        return value;
    }

  protected:
    std::int64_t value;
};
}
