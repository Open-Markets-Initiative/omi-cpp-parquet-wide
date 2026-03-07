#pragma once

#include "../bitfields/InstAttribValue.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionFuture27NoInstAttribGroup {

    InstAttribValue inst_attrib_value;

    // parse method
    static MDInstrumentDefinitionFuture27NoInstAttribGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionFuture27NoInstAttribGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionFuture27NoInstAttribGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionFuture27NoInstAttribGroup*>(buffer);
    }
};

#pragma pack(pop)
}
