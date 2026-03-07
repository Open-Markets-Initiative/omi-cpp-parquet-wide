#pragma once

#include "../types/OrderIdOptional.hpp"
#include "../types/MdOrderPriority.hpp"
#include "../types/MdEntryPxOptional.hpp"
#include "../types/MdDisplayQtyOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeBook.hpp"
#include "../types/Padding6.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDIncrementalRefreshOrderBook43NoMDEntriesGroup {

    OrderIdOptional order_id_optional;
    MdOrderPriority md_order_priority;
    MdEntryPxOptional md_entry_px_optional;
    MdDisplayQtyOptional md_display_qty_optional;
    SecurityId security_id;
    MdUpdateAction md_update_action;
    MdEntryTypeBook md_entry_type_book;
    Padding6 padding_6;

    // parse method
    static MDIncrementalRefreshOrderBook43NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDIncrementalRefreshOrderBook43NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const MDIncrementalRefreshOrderBook43NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDIncrementalRefreshOrderBook43NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
