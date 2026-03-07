#pragma once

#include "../types/MdFeedType.hpp"
#include "../types/MarketDepth.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionSpread29NoMDFeedTypesGroup {

    MdFeedType md_feed_type;
    MarketDepth market_depth;

    // parse method
    static MDInstrumentDefinitionSpread29NoMDFeedTypesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionSpread29NoMDFeedTypesGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionSpread29NoMDFeedTypesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionSpread29NoMDFeedTypesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
