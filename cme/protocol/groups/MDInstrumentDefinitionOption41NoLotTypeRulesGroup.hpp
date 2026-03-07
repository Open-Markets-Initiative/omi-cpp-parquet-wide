#pragma once

#include "../types/LotType.hpp"
#include "../types/MinLotSize.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionOption41NoLotTypeRulesGroup {

    LotType lot_type;
    MinLotSize min_lot_size;

    // parse method
    static MDInstrumentDefinitionOption41NoLotTypeRulesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionOption41NoLotTypeRulesGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionOption41NoLotTypeRulesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionOption41NoLotTypeRulesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
