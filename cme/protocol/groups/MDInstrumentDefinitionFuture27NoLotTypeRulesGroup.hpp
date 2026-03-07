#pragma once

#include "../types/LotType.hpp"
#include "../types/MinLotSize.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionFuture27NoLotTypeRulesGroup {

    LotType lot_type;
    MinLotSize min_lot_size;

    // parse method
    static MDInstrumentDefinitionFuture27NoLotTypeRulesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionFuture27NoLotTypeRulesGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionFuture27NoLotTypeRulesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionFuture27NoLotTypeRulesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
