#pragma once

#include <cstddef>

namespace siac::opra::recipient::obi::v6_2 {

// Message Type
struct AdministrativeMessageType {

    static constexpr const char* name = "Administrative Message Type";
    static constexpr std::size_t size = 1;

    // default constructor
    constexpr AdministrativeMessageType()
     : value{ 0 } {}

    // standard constructor
    constexpr explicit AdministrativeMessageType(const char value)
     : value{ value } {}

    // get value of AdministrativeMessageType field
    [[nodiscard]] char get() const {
        return value;
    }

  protected:
    char value;
};
}
