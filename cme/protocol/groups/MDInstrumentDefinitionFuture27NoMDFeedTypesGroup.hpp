#pragma once

#include "../types/MdFeedType.hpp"
#include "../types/MarketDepth.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDInstrumentDefinitionFuture27NoMDFeedTypesGroup {

    MdFeedType md_feed_type;
    MarketDepth market_depth;

    // parse method
    static MDInstrumentDefinitionFuture27NoMDFeedTypesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDInstrumentDefinitionFuture27NoMDFeedTypesGroup*>(buffer);
    }

    // parse method const
    static const MDInstrumentDefinitionFuture27NoMDFeedTypesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDInstrumentDefinitionFuture27NoMDFeedTypesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
