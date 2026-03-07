#pragma once

#include "../types/MdFeedType.hpp"
#include "../types/MarketDepth.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionOption41NoMDFeedTypesGroup {

    MdFeedType md_feed_type;
    MarketDepth market_depth;

    // parse method
    static MDInstrumentDefinitionOption41NoMDFeedTypesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionOption41NoMDFeedTypesGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionOption41NoMDFeedTypesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionOption41NoMDFeedTypesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
