#pragma once

#include "../bitfields/InstAttribValue.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionOption41NoInstAttribGroup {

    InstAttribValue inst_attrib_value;

    // parse method
    static MDInstrumentDefinitionOption41NoInstAttribGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionOption41NoInstAttribGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionOption41NoInstAttribGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionOption41NoInstAttribGroup*>(buffer);
    }
};

#pragma pack(pop)
}
