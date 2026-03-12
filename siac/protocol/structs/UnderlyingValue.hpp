#pragma once

#include "../types/UnderlyingValueMessageType.hpp"

namespace siac::opra::recipient::obi::v6_2 {

#pragma pack(push, 1)

struct UnderlyingValue {

    UnderlyingValueMessageType underlying_value_message_type;

    // parse method
    static UnderlyingValue* parse(std::byte* buffer) {
        return reinterpret_cast<UnderlyingValue*>(buffer);
    }

    // parse method const
    static const UnderlyingValue* parse(const std::byte* buffer) {
        return reinterpret_cast<const UnderlyingValue*>(buffer);
    }
};

#pragma pack(pop)
}
