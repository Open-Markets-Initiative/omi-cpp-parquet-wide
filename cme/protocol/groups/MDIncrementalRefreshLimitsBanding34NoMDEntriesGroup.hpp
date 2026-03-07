#pragma once

#include "../types/HighLimitPrice.hpp"
#include "../types/LowLimitPrice.hpp"
#include "../types/MaxPriceVariation.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup {

    HighLimitPrice high_limit_price;
    LowLimitPrice low_limit_price;
    MaxPriceVariation max_price_variation;
    SecurityId security_id;
    RptSeq rpt_seq;

    // parse method
    static MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDIncrementalRefreshLimitsBanding34NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
