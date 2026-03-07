#pragma once

#include "../types/OrderId.hpp"
#include "../types/LastQty.hpp"
#include "../types/Padding4.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup {

    OrderId order_id;
    LastQty last_qty;
    Padding4 padding_4;

    // parse method
    static MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup*>(buffer);
    }

    // parse method const
    static const MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDIncrementalRefreshTradeSummary42NoOrderIDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
