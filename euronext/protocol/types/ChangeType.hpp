#pragma once

#include <cstddef>
#include <cstdint>

namespace euronext::optiq::marketdatagateway::sbe::v5_25 {

// changeType
struct ChangeType {

    static constexpr const char* name = "Change Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr ChangeType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit ChangeType(const std::uint8_t value)
     : value{ value } {}

    // get value of ChangeType field
    [[nodiscard]] std::uint8_t get() const {
        return value;
    }

  protected:
    std::uint8_t value;
};
}
