#pragma once

#include "../types/MdEntryPxOptional.hpp"
#include "../types/MdEntrySizeOptional.hpp"
#include "../types/SecurityId.hpp"
#include "../types/RptSeq.hpp"
#include "../types/TradingReferenceDate.hpp"
#include "../bitfields/SettlPriceType.hpp"
#include "../types/MdUpdateAction.hpp"
#include "../types/MdEntryTypeDailyStatistics.hpp"
#include "../types/Padding7.hpp"

namespace cme::mdp3::v8 {

#pragma pack(push, 1)

struct MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup {

    MdEntryPxOptional md_entry_px_optional;
    MdEntrySizeOptional md_entry_size_optional;
    SecurityId security_id;
    RptSeq rpt_seq;
    TradingReferenceDate trading_reference_date;
    SettlPriceType settl_price_type;
    MdUpdateAction md_update_action;
    MdEntryTypeDailyStatistics md_entry_type_daily_statistics;
    Padding7 padding_7;

    // parse method
    static MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup* parse(std::byte* buffer) {
        return reinterpret_cast<MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup*>(buffer);
    }

    // parse method const
    static const MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup* parse(const std::byte* buffer) {
        return reinterpret_cast<const MDIncrementalRefreshDailyStatistics33NoMDEntriesGroup*>(buffer);
    }
};

#pragma pack(pop)
}
