#pragma once

#include "../bitfields/InstAttribValue.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionSpread29NoInstAttribGroup {

    InstAttribValue inst_attrib_value;

    // parse method
    static MDInstrumentDefinitionSpread29NoInstAttribGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionSpread29NoInstAttribGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionSpread29NoInstAttribGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionSpread29NoInstAttribGroup*>(buffer);
    }
};

#pragma pack(pop)
}
