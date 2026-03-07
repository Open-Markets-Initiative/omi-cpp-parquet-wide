#pragma once

#include "../types/RelatedSecurityId.hpp"
#include "../types/RelatedSymbol.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup {

    RelatedSecurityId related_security_id;
    RelatedSymbol related_symbol;

    // parse method
    static MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionOption41NoRelatedInstrumentsGroup*>(buffer);
    }
};

#pragma pack(pop)
}
