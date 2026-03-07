#pragma once

#include "../types/UnderlyingSecurityId.hpp"
#include "../types/UnderlyingSymbol.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionOption41NoUnderlyingsGroup {

    UnderlyingSecurityId underlying_security_id;
    UnderlyingSymbol underlying_symbol;

    // parse method
    static MDInstrumentDefinitionOption41NoUnderlyingsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionOption41NoUnderlyingsGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionOption41NoUnderlyingsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionOption41NoUnderlyingsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
