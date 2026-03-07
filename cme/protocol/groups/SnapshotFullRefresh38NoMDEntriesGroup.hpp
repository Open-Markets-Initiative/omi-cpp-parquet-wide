#pragma once

#include "../types/MdEntryPxOptional.hpp"
#include "../types/MdEntrySizeOptional.hpp"
#include "../types/NumberOfOrders.hpp"
#include "../types/MdPriceLevelOptional.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../types/OpenCloseSettlFlag.hpp"
#include "../bitfields/SettlPriceType.hpp"
#include "../types/MdEntryType.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct SnapshotFullRefresh38NoMDEntriesGroup {

    MdEntryPxOptional md_entry_px_optional;
    MdEntrySizeOptional md_entry_size_optional;
    NumberOfOrders number_of_orders;
    MdPriceLevelOptional md_price_level_optional;
    TradingReferenceDate trading_reference_date;
    OpenCloseSettlFlag open_close_settl_flag;
    SettlPriceType settl_price_type;
    MdEntryType md_entry_type_;

    // parse method
    static SnapshotFullRefresh38NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<SnapshotFullRefresh38NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const SnapshotFullRefresh38NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const SnapshotFullRefresh38NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
