#pragma once

#include "../types/OrderId.hpp"
#include "../types/MdOrderPriority.hpp"
#include "../types/MdEntryPx.hpp"
#include "../types/MdDisplayQty.hpp"
#include "../types/MdEntryTypeBook.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct SnapshotFullRefreshOrderBook44NoMDEntriesGroup {

    OrderId order_id;
    MdOrderPriority md_order_priority;
    MdEntryPx md_entry_px;
    MdDisplayQty md_display_qty;
    MdEntryTypeBook md_entry_type_book;

    // parse method
    static SnapshotFullRefreshOrderBook44NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefreshOrderBook44NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefreshOrderBook44NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefreshOrderBook44NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
