#pragma once

#include "../types/LotType.hpp"
#include "../types/MinLotSize.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionSpread29NoLotTypeRulesGroup {

    LotType lot_type;
    MinLotSize min_lot_size;

    // parse method
    static MDInstrumentDefinitionSpread29NoLotTypeRulesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionSpread29NoLotTypeRulesGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionSpread29NoLotTypeRulesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionSpread29NoLotTypeRulesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
