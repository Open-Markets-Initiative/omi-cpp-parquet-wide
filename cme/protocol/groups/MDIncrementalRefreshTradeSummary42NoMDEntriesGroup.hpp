#pragma once

#include "../types/MdEntryPx.hpp"
#include "../types/MdEntrySize.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/NumberOfOrders.hpp"
#include "../types/AggressorSide.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdTradeEntryId.hpp"
#include "../types/Padding2.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDIncrementalRefreshTradeSummary42NoMDEntriesGroup {

    MdEntryPx md_entry_px;
    MdEntrySize md_entry_size;
    SecurityId security_id;
    RptSeq rpt_seq;
    NumberOfOrders number_of_orders;
    AggressorSide aggressor_side;
    MdUpdateAction md_update_action;
    MdTradeEntryId md_trade_entry_id;
    Padding2 padding_2;

    // parse method
    static MDIncrementalRefreshTradeSummary42NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDIncrementalRefreshTradeSummary42NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const MDIncrementalRefreshTradeSummary42NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDIncrementalRefreshTradeSummary42NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
