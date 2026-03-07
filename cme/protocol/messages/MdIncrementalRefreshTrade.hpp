#pragma once

#include "../types/TransactTime.hpp"
#include "../bitfields/MatchEventIndicator.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

// MDIncrementalRefreshTrade
struct MdIncrementalRefreshTrade {

    TransactTime transact_time;
    MatchEventIndicator match_event_indicator;
    Padding2 padding_2;

    // parse method
    static MdIncrementalRefreshTrade* parse(std::byte* buffer) {
        return reinterpret_cast<MdIncrementalRefreshTrade*>(buffer);
    }

    // parse method const
    static const MdIncrementalRefreshTrade* parse(const std::byte* buffer) {
        return reinterpret_cast<const MdIncrementalRefreshTrade*>(buffer);
    }
};

#pragma pack(pop)
}
