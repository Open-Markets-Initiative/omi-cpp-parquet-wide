#pragma once

#include "../types/MdEntryPxOptional.hpp"
#include "../types/MdEntrySizeOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/NumberOfOrders.hpp"
#include "../types/MdPriceLevel.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeBook.hpp"
#include "../types/Padding5.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDIncrementalRefreshBook32NoMDEntriesGroup {

    MdEntryPxOptional md_entry_px_optional;
    MdEntrySizeOptional md_entry_size_optional;
    SecurityId security_id;
    RptSeq rpt_seq;
    NumberOfOrders number_of_orders;
    MdPriceLevel md_price_level;
    MdUpdateAction md_update_action;
    MdEntryTypeBook md_entry_type_book;
    Padding5 padding_5;

    // parse method
    static MDIncrementalRefreshBook32NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDIncrementalRefreshBook32NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const MDIncrementalRefreshBook32NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDIncrementalRefreshBook32NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
